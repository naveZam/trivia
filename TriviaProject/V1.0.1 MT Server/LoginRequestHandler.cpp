#include "LoginRequestHandler.h"

#define LOG_IN_REQUEST 1

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LOG_IN_REQUEST)
        return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	
	RequestResult result;
	result.newHandler = this;
	result.response = info.buffer;
	return result;
}
