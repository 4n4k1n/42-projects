#pragma once

#include "webserv.hpp"
#include "ServerConfig.hpp"

class Config {
    public:
        std::vector<ServerConfig> servers;
};