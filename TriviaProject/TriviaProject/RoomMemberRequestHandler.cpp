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
		break;
	case GetRoomStateRequest:
		result = getRoomState(info);
		break;
	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	}


	
	return result;
}

RequestResult RoomMemberRequestHandler::leaveRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	std::string response;
	try
	{
		m_room.removeUser(M_user);
		result.response = nonError;
		response = JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse());
	}
	catch (const std::exception&)
	{
		ErrorResponse ErrorRes;
		response = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		
	}
	result.response = std::vector<unsigned char>(response.begin(), response.end());
	return result;
}

RequestResult RoomMemberRequestHandler::getRoomState(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	try
	{
		GetRoomStateResponse GetRoomRes = GetRoomStateResponse();
		RoomData roomData = m_room.getRoomData();
		GetRoomRes.status = 1;
		GetRoomRes.players = m_room.getAllUsers();
		GetRoomRes.questionCount = roomData.numOfQuestionsInGame;
		GetRoomRes.answerTimeOut = roomData.timePerQuestion;
		GetRoomRes.hasGameBegun = roomData.isActive;

		std::string Respones = JsonResponsePacketSerializer::serializeResponse(GetRoomRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
	catch (...)
	{
		ErrorResponse ErrorRes;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
	

}


