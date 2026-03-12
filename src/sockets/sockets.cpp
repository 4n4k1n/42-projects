#include "sockets.hpp"

void setup_sockets(void)
{

    int socket_fd;
    struct addrinfo hints;

    memset(&hints, 0 , sizeof(hints));
    hints.ai_family = AF_UNSPEC;
    hints.ai_socktype = SOCK_STREAM;
    hints.ai_flags = AI_PASSIVE;

    int status;
    std::string port("8080");

    struct addrinfo *results;
    status = getaddrinfo(NULL, port.c_str(), &hints, &results);
    if(status != 0)
    {
        std::cerr << RED << "getaddrinfo error: " << gai_strerror(status) << RESET << std::endl;
        return ;
    }

    socket_fd = socket(results->ai_family, results->ai_socktype, results->ai_protocol);
    if(socket_fd == -1)
    {
        std::cerr << RED << "socket error: " << strerror(errno) << RESET << std::endl;
        freeaddrinfo(results);
        return ;
    }
    std::cout << GREEN << "Socket created " << socket_fd << RESET << std::endl;

     int opt = 1;
    if (setsockopt(socket_fd, SOL_SOCKET, SO_REUSEADDR, &opt, sizeof(opt)) == -1)
    {
        std::cerr << RED << "setsockopt error: " << strerror(errno) << RESET << std::endl;
        freeaddrinfo(results);
        return ;
    }
    std::cout << GREEN << "Socket options set"  << RESET << std::endl;


    if (fcntl(socket_fd, F_SETFL, O_NONBLOCK) == -1)
    {
        std::cerr << RED << "fcntl error: " << strerror(errno) << RESET << std::endl;
        freeaddrinfo(results);
        return ;
    }
    std::cout << GREEN << "Socket set to non-blocking" << RESET << std::endl;

    if (bind(socket_fd, results->ai_addr, results->ai_addrlen) == -1)
    {
        std::cerr << RED << "bind error: " << strerror(errno) << RESET << std::endl;
        close(socket_fd);
        freeaddrinfo(results);
        return ;
    }
    std::cout << GREEN << "Socket bound to port " << port << RESET << std::endl;
    if (listen(socket_fd, SOMAXCONN) == -1)
    {
        std::cerr << RED << "listen error: " << strerror(errno) << RESET << std::endl;
        close(socket_fd);
        freeaddrinfo(results);
        return ;
    }
    std::cout << GREEN << "Socket listening on port " << port << RESET << std::endl;
    freeaddrinfo(results);
}
