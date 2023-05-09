#pragma once
#include "Room.h"
#include <map>

class RoomManager
{
public:
	RoomManager();
	void createRoom(LoggedUser owner, RoomData newRoomData);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);

private:
	static unsigned int m_newId;
	std::map<roomID, Room> m_rooms;
};

