#pragma once

#include "IDatabase.h"
#include "sqlite3.h"
#include <string>
#define DATABASE_NAME "database.db"


class SqliteDataBase : public IDatabase
{
public:
	static SqliteDataBase* getInstance();
	SqliteDataBase(const SqliteDataBase& obj) = delete;
	~SqliteDataBase();
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
	void addGame(std::string name, int correctAnswers, int wrongAnswers, float averageAnswerTime);
	void addQuestions();
	

private:
	static SqliteDataBase* instancePtr;
	SqliteDataBase();
	sqlite3* db;
};

