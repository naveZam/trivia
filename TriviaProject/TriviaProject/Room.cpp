#include "Room.h"
int Room::ID = 0;
Room::Room(LoggedUser owner, RoomData data)
{
	data.id = Room::ID;
	data.isActive = false;
	ID++;
	this->m_metadata = data;
	m_users.clear();
	this->m_users.push_back(owner); //the owner is the front
	this->status = 1;
}

void Room::addUser(LoggedUser user)
{
	for (auto it = m_users.begin(); it != m_users.end(); it++)
	{
		if (it->getUsername() == user.getUsername())
		{
			std::cout << "User Was already in the room" << std::endl;
			return;
		}
	}
	this->m_users.push_back(user);
}

void Room::removeUser(LoggedUser user)
{
	int i = 0;
	for (auto it = m_users.begin(); it != m_users.end(); it++)
	{
		if (it->getUsername() == user.getUsername())
		{
			break;
		}
		i++;
	}

	if (i >= m_users.size())
	{
		std::cout << "User not in the room" << std::endl;
		return;
	}

	this->m_users.erase(m_users.begin() + i);
}

std::vector<std::string> Room::getAllUsers()
{
	std::vector<std::string> allUsers;
	allUsers.clear();
	for (auto it = m_users.begin(); it != m_users.end(); it++)
	{
		allUsers.push_back(it->getUsername());
	}
	return allUsers;
}

bool Room::getState()
{
	return m_metadata.isActive;
}

RoomData& Room::getRoomData()
{
	return m_metadata;
}
