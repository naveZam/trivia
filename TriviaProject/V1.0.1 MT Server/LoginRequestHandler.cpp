#include "LoginRequestHandler.h"

#define LOG_IN_REQUEST 1
#define SIGN_UP_REQUEST 2

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LOG_IN_REQUEST || info.id == SIGN_UP_REQUEST)
        return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new LoginRequestHandler;
	result.response = info.buffer;
	return result;
}
