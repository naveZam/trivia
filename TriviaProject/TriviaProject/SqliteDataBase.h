#pragma once

#include "IDatabase.h"
#include "sqlite3.h"
#include "Singleton.h"

#define DATABASE_NAME "database.db"

class SqliteDataBase : public IDatabase
{
	MAKE_SINGLETON_CLASS(SqliteDataBase)

public:
	bool open();
	bool close();
	int doesUserExist(std::string username);
	int doesPasswordMatch(std::string username, std::string password);
	int addNewUser(std::string username, std::string password, std::string email);
	Question getQuestions(int questionsNo);
	float getAverageAnswerTime(std::string name);
	int getNumOfCorrectAnswers(std::string name);
	int getNumOfTotalAnswers(std::string name);
	int getNumOfPlayerGames(std::string name);
	int getPlayerScore(std::string name);
	std::vector<std::string> getBestScores();
	void addGame(int id, std::string name, int correctAnswers, int wrongAnswers, float averageAnswerTime, int score);
	void addQuestions();
	

private:
	sqlite3* db;
};

