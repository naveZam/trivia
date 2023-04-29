#include "LoginRequestHandler.h"

#define SIGN_UP_REQUEST 1

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == SIGN_UP_REQUEST)
        return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
    return RequestResult();
}
