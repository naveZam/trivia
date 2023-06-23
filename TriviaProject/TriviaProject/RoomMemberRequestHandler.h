#pragma once
#include "Room.h"
#include "LoggedUser.h"
#include "IRequestHandler.h"
#include "JsonRequestPacketDeserializer.h"
#include "RoomManager.h"
class RoomMemberRequestHandler : public IRequestHandler
{
public:
	RoomMemberRequestHandler(Room room, LoggedUser user);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info) override;
	Room getRoom() { return m_room; }
	LoggedUser getUser() { return M_user; }
private:
	Room m_room;
	LoggedUser M_user;
	RequestResult leaveRoom(RequestInfo info);
	RequestResult getRoomState(RequestInfo info);
};

