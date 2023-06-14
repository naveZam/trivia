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
	std::string errorResponse = "1";
	std::vector<unsigned char> error = std::vector<unsigned char>(errorResponse.begin(), errorResponse.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;
	RequestResult request;
	
	switch (info.id)
	{
	case LeaveGameRequestCode:
	
		result = leaveRoom(info);
		if (result.response == error)
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		else
			Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		break;
	case GetRoomStateRequest:
		result = getRoomState(info);
		if (result.response == error)
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		else
			Respones = JsonResponsePacketSerializer::serializeResponse(getRoomStateResponse(result));
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

	GetRoomStateResponse getRoomStateRes;
	result.response.push_back(m_room.getRoomData().id);

	return result;
	

}

GetRoomStateResponse RoomMemberRequestHandler::getRoomStateResponse(RequestResult result)
{
	GetRoomStateResponse getRoomStateRes;
	RoomManager* manager = RoomManager::getInstance();
	RoomData roomData = m_room.getRoomData();
	getRoomStateRes.status = roomData.id;
	getRoomStateRes.players = m_room.getAllUsers();
	getRoomStateRes.questionCount = roomData.numOfQuestionsInGame;
	getRoomStateRes.hasGameBegun = roomData.isActive;
	return getRoomStateRes;
}
