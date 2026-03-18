#include "socket/sockets.hpp"
#include "socket/Connection_class.hpp"

Connection create_client_socket(Connection con)
{
    struct sockaddr_in client_addr;
    socklen_t client_addr_len = sizeof(client_addr);
    
    int client_fd = accept(con._poll_fd.fd, 
                 (struct sockaddr *)&client_addr, 
                  &client_addr_len);
    if(client_fd == -1){
        std::cerr << RED << "accept error" << RESET << std::endl;
    } else {
        std::cout << GREEN << "Client connected: " << client_fd << RESET << std::endl;
    }
    
    if (fcntl(client_fd, F_SETFL, O_NONBLOCK) == -1)
    {
        std::cerr << RED << "fcntl error: " << strerror(errno) << RESET << std::endl;
        exit(-1);
    }

    Connection client_socket;
    client_socket._poll_fd.fd = client_fd;
    client_socket._poll_fd.events = POLLIN;
    client_socket._poll_fd.revents = 0;
    client_socket._fd_flag = CLIENT_FD;
    
    return(client_socket);
}

void handleRequest(Connection con)
{
    char buffer[200];
    ssize_t bytes = recv(con._poll_fd.fd, buffer, sizeof(buffer), 0);
    if(bytes == 0){
        std::cout << YELLOW << "Client disconnected" << RESET << std::endl;
        return ;
    } else if (bytes == -1){
        std::cerr << RED << "recv error: " << strerror(errno) << RESET << std::endl;
        return ;
    }

    buffer[bytes] = '\0';
    con._read_buffer.append(buffer, bytes);
    std::cout << BOLD << BLUE << con._read_buffer << RESET << std::endl;
}
