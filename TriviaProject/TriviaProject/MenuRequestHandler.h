#pragma once
#include "LoginRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "LoggedUser.h"
#include "JsonResponsePacketSerializer.h"

class MenuRequestHandler : public IRequestHandler
{
public:
	MenuRequestHandler(LoggedUser user);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);
	

private:
	LoggedUser m_user;
	RequestResult signout(RequestInfo info);
	RequestResult getRooms(RequestInfo info);
	RequestResult getPlayersInRoom(RequestInfo info);
	RequestResult getPersonalStats(RequestInfo info);
	RequestResult joinRoom(RequestInfo info);
	RequestResult createRoom(RequestInfo info);
	RequestResult getHighScore(RequestInfo info);

};

