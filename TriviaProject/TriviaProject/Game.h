#pragma once

#include "Structs.h"
#include "LoggedUser.h"
#include "Question.h"

class Game
{
public:
	Question getQuestionForUser(LoggedUser user);
	void submitAnswer();
	void removePlayer();

private:
	void sumitGameStatsToDB(GameData data);

	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	int m_gameId;
};

