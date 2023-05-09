#pragma once

#include "IDatabase.h"
#include "sqlite3.h"
#define DATABASE_NAME "database.db"

class SqliteDataBase : public IDatabase
{
public:
	SqliteDataBase();
	~SqliteDataBase();
	bool open();
	bool close();
	int doesUserExist(std::string username);
	int doesPasswordMatch(std::string username, std::string password);
	int addNewUser(std::string username, std::string password, std::string email);
	Question getQuestions(int questionsNo);
	float getAverageAnswerTime();
	int getNumOfCorrectAnswers();
	int getNumOfTotalAnswers();
	int getNumOfPlayerGames();
	int getPlayerScore();
	std::vector<std::string> getBestScores();
	

private:
	sqlite3* db;
};

