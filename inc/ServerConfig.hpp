#pragma once

#include "webserv.hpp"
class LocationConfig;

class ServerConfig {
    public:
        int port;
        std::string host;
        std::string index;

        std::vector<LocationConfig> locations;
};