#include "GameRequestHandler.h"

bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LeaveGameRequestCode || info.id == GetQuestionRequestCode || info.id == SubmitAnswerRequestCode || info.id == GetGameResultRequestCode)
    {
        return true;
    }
    return false;
}

RequestResult GameRequestHandler::handleRequest(RequestInfo info)
{
    RequestResult result;

    std::string notErrorrRespond = "1";
    std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());

    switch (info.id)
    {
    case LeaveGameRequestCode:
        break;

    case GetQuestionRequestCode:
        break;

    case SubmitAnswerRequestCode:
        break;

    case GetGameResultRequestCode:
        break;
    }

    return RequestResult();
}
