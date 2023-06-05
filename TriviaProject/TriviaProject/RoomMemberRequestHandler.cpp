#include "RoomMemberRequestHandler.h"

RoomMemberRequestHandler::RoomMemberRequestHandler(Room room, LoggedUser user) : m_room(room), M_user(user)
{
}

bool RoomMemberRequestHandler::isRequestRelevant(RequestInfo info)
{
	if (info.id == RoomMemberRequestHandlerCode || info.id == LeaveRoomRequest || info.id == GetRoomStateRequest)
		return true;
	return false;
}

RequestResult RoomMemberRequestHandler::handleRequest(RequestInfo info)
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
	case RoomMemberRequestHandlerCode:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	return result;
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == LeaveRoomRequest)
	{
		m_room.removeUser(M_user);
		result.response = nonError;
		return result;
	}
	else
	{
		ErrorResponse ErrorRes;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
	
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == GetRoomStateRequest)
	{
		GetRoomStateResponse getRoomStateRes;
		getRoomStateRes.status = m_room.getRoomData().isActive;
		getRoomStateRes.players = m_room.getAllUsers();
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(getRoomStateRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
	else
	{
		ErrorResponse ErrorRes;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
}
