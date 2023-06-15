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
        result = leaveGame(info);
        break;

    case GetQuestionRequestCode:
        result = getQuestion(info);
        break;

    case SubmitAnswerRequestCode:
        result = submitAnswer(info);
        break;

    case GetGameResultRequestCode:
        break;
    }

    return result;
}

RequestResult GameRequestHandler::getQuestion(RequestInfo info)
{
    RequestResult result;
    ErrorResponse ErrorRes;
    GetQuestionResponse getQuestionRes;
    std::string Respones = "";
    
    Question q = m_game.getQuestionForUser(m_user);    
    Respones = q.getQuestion();

    getQuestionRes.status = 1;
    getQuestionRes.question = q.getQuestion();

    std::map<unsigned int, std::string> mapAns;
    unsigned int key = 0;

    for (const auto& element : q.getPossibleAnswers()) {
        mapAns[key++] = element;
    }

    getQuestionRes.answers = mapAns;

    if (Respones == "error")
    {
        Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
    }
    Respones = JsonResponsePacketSerializer::serializeResponse(getQuestionRes);

    result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
    result.newHandler = this;
    return result;
}

RequestResult GameRequestHandler::submitAnswer(RequestInfo info)
{
    RequestResult result;
    ErrorResponse ErrorRes;
    SubmitAnswerResponse subAnsRes;
    std::string Respones = "";

    SubmitAnswerRequest req = JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(info.buffer);
    m_game.submitAnswer(m_user, req.answerId);

    subAnsRes.correctAnswerId = 0;
    subAnsRes.status = 1;

    Respones = JsonResponsePacketSerializer::serializeResponse(subAnsRes);

    result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
    result.newHandler = this;
    return result;
}

RequestResult GameRequestHandler::getGameResults(RequestInfo info)
{
    RequestResult result;
    ErrorResponse ErrorRes;
    GetGameResultsResponse gameResultRes;
    std::string Respones = "";

    

    result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
    result.newHandler = this;
    return result;
}

RequestResult GameRequestHandler::leaveGame(RequestInfo info)
{
    int i = 0;
    RequestResult result;
    LeaveGameResponse response;
    result.newHandler = this;

    for (i = 0; i < RoomManager::getInstance()->getRooms().size(); i++)
    {
        Room room = RoomManager::getInstance()->getRoom(i);
        std::vector<std::string> players = room.getAllUsers();

        for (auto it = players.begin(); it != players.end(); i++)
        {
            if (*it == m_user.getUsername())
            {
                RoomManager::getInstance()->getRoom(i).removeUser(m_user);
                std::string Respones = JsonResponsePacketSerializer::serializeResponse(response);
                result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
                return result;
            }
        }
    }

    ErrorResponse ErrorRes;
    std::string Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
    result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
    return result;
}
