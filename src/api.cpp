#include "api.hpp"
#include "hid.hpp"

LibApi::LibApi()
	: m_listener(U("http://localhost:6200"))
{
	ConfigureRoutes();
}

void LibApi::Start()
{
	m_listener.open().wait();
}

void LibApi::ConfigureRoutes()
{
	m_listener.support(methods::POST, std::bind(&LibApi::HandlePostRequest, this, std::placeholders::_1));
}

void LibApi::HandlePostRequest(http_request request)
{
	utility::string_t path = request.relative_uri().path();

	if (path == U("/Playground"))
	{
		playground();
		request.reply(status_codes::OK);
	}

	else
	{
		request.reply(status_codes::NotFound);
	}
}
