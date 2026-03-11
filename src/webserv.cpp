#include "webserv.hpp"

void webServ(char *filename)
{
    parse_config(filename);
    setup_sockets();
}