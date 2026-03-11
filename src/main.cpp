#include "webserv.hpp"

int main(int argc, char *argv[])
{
    if(argc != 2)
    {
        std::cout << RED << "wrong number of arguments" << RESET << std::endl;
        return(-1);
    }
    webServ(argv[1]);
    return (0);
}