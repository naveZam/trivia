#pragma once
#include "Room.h"
#include <map>

class RoomManager
{
public:
	static RoomManager* getInstance();
	
	void createRoom(LoggedUser owner, RoomData newRoomData);
	void deleteRoom(int ID);
	unsigned int getRoomState(int ID);
	std::vector<RoomData> getRooms();
	Room& getRoom(int ID);
	Room& getRoomById(int ID);

private:
	 
	RoomManager();
	static unsigned int m_newId;
	std::map<roomID, Room> m_rooms;
	static RoomManager* instancePtr;
};

