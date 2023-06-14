#pragma once

#include "Game.h"
#include "Room.h"
#include "SqliteDataBase.h"

class GameManager
{
public:
	Game createGame(Room room);
	void deleteGame(int gameId);

private:
	std::vector<Game> m_games;
};