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

	StartGameResponse StartRes = StartGameResponse();
	LeaveRoomResponse LeaveRes = LeaveRoomResponse();
	ErrorResponse ErrorRes;

	StartRes.status = 1;
	LeaveRes.status = 1;

	std::string Respones;

	switch (info.id)
	{
	case CloseRoomRequest:
		Respones = JsonResponsePacketSerializer::serializeResponse(LeaveRes);
		break;

	case StartGameRequest:
		Respones = JsonResponsePacketSerializer::serializeResponse(StartRes);
		break;

	case GetRoomStateRequest:
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	return result;
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == CloseRoomRequest)
	{
		LeaveRoomResponse LeaveRes = LeaveRoomResponse();
		LeaveRes.status = 1;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(LeaveRes);
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

RequestResult RoomAdminRequestHandler::startGame(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == StartGameRequest)
	{
		StartGameResponse StartRes = StartGameResponse();
		StartRes.status = 1;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(StartRes);
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

RequestResult RoomAdminRequestHandler::getRoomState(RequestInfo info)
{
	RequestResult result;
	result.newHandler = this;
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == GetRoomStateRequest)
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
	else
	{
		ErrorResponse ErrorRes;
		std::string Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
		return result;
	}
}
