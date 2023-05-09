#include "RoomManager.h"

RoomManager::RoomManager()
{
    m_rooms.clear();
}

void RoomManager::createRoom(LoggedUser owner, RoomData newRoomData)
{
    Room newRoom = Room(owner, newRoomData);
    m_newId++;
    m_rooms.insert(std::pair<roomID, Room>(m_newId, newRoom));
}

void RoomManager::deleteRoom(int ID)
{
    auto it = m_rooms.find(ID);

    if (it != m_rooms.end()) 
    {
        m_rooms.erase(it);
    }
}

unsigned int RoomManager::getRoomState(int ID)
{
    auto it = m_rooms.find(ID);
    return it->second.getState();
}

std::vector<RoomData> RoomManager::getRooms()
{
    std::vector<RoomData> roomsData;
    roomsData.clear();

    for (auto it = m_rooms.begin(); it != m_rooms.end(); it++)
    {
        if (!it->second.getState())
        {
            roomsData.push_back(it->second.getRoomData());
        }
    }

    return roomsData;
}

Room& RoomManager::getRoom(int ID)
{
    auto it = m_rooms.find(ID);
    return it->second;
}
