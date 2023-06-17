#pragma once

#include "Structs.h"
#include "LoggedUser.h"
#include "Question.h"
#include "SqliteDataBase.h"

class Game
{
public:
	Game(std::vector<Question> questions, std::map<LoggedUser, GameData> players);
	Question getQuestionForUser(LoggedUser user);
	void submitAnswer(LoggedUser user, int ansId);
	void removePlayer(LoggedUser user);

private:
	void submitGameStatsToDB(GameData data);

	std::vector<Question> m_questions;
	std::map<LoggedUser, GameData> m_players;
	int currentQuestion = 0;
	static int m_gameId;
};

