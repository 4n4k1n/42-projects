#include "socket/sockets.hpp"
#include "socket/Connection_class.hpp"

void print_poll_fds(std::vector<Connection> &poll_fds)
{
    std::cout << YELLOW << "Poll list size: " << poll_fds.size() << RESET << std::endl;
    for (size_t i = 0; i < poll_fds.size(); i++){
        std::cout << YELLOW << "FD[" << i << "]: " << poll_fds[i]._poll_fd.fd << RESET << std::endl;
    }
}
