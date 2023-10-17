#pragma once

#include "pch.hpp"
#include <cpprest/http_listener.h>
#include <cpprest/json.h>

using namespace web::http;

class LibApi {
public:
    LibApi();
    void Start();

private:
    void ConfigureRoutes();
    void HandlePostRequest(http_request request);

    experimental::listener::http_listener m_listener;
};