#pragma once

#include "webserv.hpp"
#include "Config.hpp"

class ConfigParser {
    public:
        Config parse(const std::string& filename);

    private:
        void parseServer(std::stringstream& ss, Config& config);
        void parseLocation(std::stringstream& ss, ServerConfig& server);
};
