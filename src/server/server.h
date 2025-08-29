#pragma once
#include <httplib.h>

class Server {
private:
    httplib::Server server;
    void setupRoutes();

public:
    void start();
};