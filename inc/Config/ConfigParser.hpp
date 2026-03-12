#pragma once

#include "webserv.hpp"
#include "Config.hpp"

class ConfigParser {
    public:
        Config parse(const std::string& config);

    private:
        void parseServer(std::stringstream& ss, Config& config);
        void parseLocation(std::stringstream& ss, ServerConfig& server);
}
