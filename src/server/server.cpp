#include "server.h"
#include <iostream>

void Server::setupRoutes() {
    server.Get("/", [](const httplib::Request& req, httplib::Response& res) {
        res.set_content("Hello, FridgeGen Server is running!", "text/plain");
    });
    
    server.Get("/api/health", [](const httplib::Request& req, httplib::Response& res) {
        std::string jsonResponse = R"({"status": "healthy", "message": "FridgeGen API is running"})";
        res.set_content(jsonResponse, "application/json");
    });
    
    server.Post("/api/generate", [](const httplib::Request& req, httplib::Response& res) {
        std::string jsonResponse = R"({"message": "Recipe generation endpoint - coming soon!", "received": ")" + req.body + R"("})";
        res.set_content(jsonResponse, "application/json");
    });
}

void Server::start() {
    setupRoutes();
    
    std::cout << "Starting FridgeGen server on http://localhost:8080" << std::endl;
    std::cout << "Endpoints:" << std::endl;
    std::cout << "  GET  /           - Welcome message" << std::endl;
    std::cout << "  GET  /api/health - Health check" << std::endl;
    std::cout << "  POST /api/generate - Recipe generation (placeholder)" << std::endl;
    
    server.listen("localhost", 8080);
}