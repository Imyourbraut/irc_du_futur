#include "ConfigurationServer.h"

ConfigurationServer::ConfigurationServer(std::string &filename) : Configuration(filename) {
    generateDefault();
}

void ConfigurationServer::generateDefault() {
    //TRIED SO HARD TO DO SOMETHING LIKE: T Configuration::setDefault(nlohmann::json &element, T value);
    if (!json["server"]["name"].is_string()) json["server"]["name"] = "irc_du_futur default server";
    if (!json["server"]["motd"].is_string()) json["server"]["motd"] = "Welcome on the server !";
    if (!json["server"]["max_connections"].is_number()) json["server"]["max_connections"] = 64;

    save();
}

void ConfigurationServer::setServerName(std::string servername) {
    json["server"]["name"] = servername;
}

std::string ConfigurationServer::getServername() {
    return json["server"]["name"];
}

void ConfigurationServer::setMotd(std::string motd) {
    json["server"]["motd"] = motd;
}

std::string ConfigurationServer::getMotd() {
    return json["server"]["motd"];
}

void ConfigurationServer::setMaxConnections(int maxconnections) {
    json["server"]["max_connections"] = maxconnections;
}

int ConfigurationServer::getMaxConnections() {
    return json["server"]["max_connections"];
}
