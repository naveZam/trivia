#pragma once
#include <vector>

#include "Structs.h"
#include "LoggedUser.h"

class Room
{
public:
	Room(LoggedUser owner, RoomData data);
	void addUser(LoggedUser user);
	void removeUser(LoggedUser user);
	std::vector<std::string> getAllUsers();
	bool getState();
	RoomData& getRoomData();
	void close() { status = 0; }
	int getStatus() { return status; }
private:
	RoomData m_metadata;
	std::vector<LoggedUser> m_users;
	static int ID;
	int status;
};

