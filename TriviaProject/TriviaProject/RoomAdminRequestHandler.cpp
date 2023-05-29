#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(Room room, LoggedUser user) : m_room(room), M_user(user)
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == RoomAdminRequest || info.id == CloseRoomRequest || info.id == StartGameRequest || info.id == GetRoomStateRequest)
        return true;
    return false;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo info)
{
    RequestResult result;
    result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;

	switch (info.id)
	{
	case 420:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	return result;
}
