#include "RoomAdminRequestHandler.h"

RoomAdminRequestHandler::RoomAdminRequestHandler(Room room, LoggedUser user) : m_room(room), M_user(user)
{
}

bool RoomAdminRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == RoomAdminRequest || info.id == CloseRoomRequest || info.id == StartGameRequest || info.id == GetRoomStateRequest || info.id == LeaveRoomRequest)
        return true;
    return false;
}

RequestResult RoomAdminRequestHandler::handleRequest(RequestInfo info)
{
    RequestResult result;
    result.newHandler = this;
	std::string errorResponse = "0";
	std::vector<unsigned char> error = std::vector<unsigned char>(errorResponse.begin(), errorResponse.end());

	StartGameResponse StartRes = StartGameResponse();
	LeaveRoomResponse LeaveRes = LeaveRoomResponse();
	GetRoomStateResponse GetRoomRes = GetRoomStateResponse();
	ErrorResponse ErrorRes;

	StartRes.status = 1;
	LeaveRes.status = 1;
	GetRoomRes.status = 1;

	std::string Respones;
	RequestResult request;
	switch (info.id)
	{
	case LeaveRoomRequest:
		request = closeRoom(info);
		break;

	case StartGameRequest:
		request = startGame(info);
		break;

	case GetRoomStateRequest:
		request = getRoomState(info);
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	}
	
	return request;
}

RequestResult RoomAdminRequestHandler::closeRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = RequestHandlerFactory::getInstance()->createMenuRequestHandler(M_user);
	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	if (info.id == LeaveRoomRequest)
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



