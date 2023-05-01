#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

class LoginRequestHandler : public IRequestHandler
{
public:
	LoginRequestHandler();
	bool isRequestRelevant(RequestInfo info) override;
	RequestResult handleRequest(RequestInfo info) override;

private:
	RequestResult login(RequestInfo);
	RequestResult signup(RequestInfo);

	RequestHandlerFactory& m_handlerFactory;
};

