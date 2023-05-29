#pragma once
#include "Room.h"
#include "LoggedUser.h"
#include "IRequestHandler.h"
class RoomAdminRequestHandler : IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info) override;

private:
	Room m_room;
	LoggedUser M_user;
	RequestResult closeRoom(RequestInfo info);
	RequestResult startGame(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);

};

