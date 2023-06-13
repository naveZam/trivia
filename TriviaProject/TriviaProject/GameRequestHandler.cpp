#include "GameRequestHandler.h"

bool GameRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LeaveGameRequestCode || info.id == GetQuestionRequestCode || info.id == SubmitAnswerRequestCode || info.id == GetGameResultRequestCode)
    {
        return true;
    }
    return false;
}
