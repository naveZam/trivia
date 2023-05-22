#pragma once
#include <vector>
#include <iostream>

#include "SqliteDataBase.h"

class RequestHandlerFactory;
class LoginRequestHandler;

class StatisticsManager
{
public:
	static StatisticsManager* getInstance();
	std::vector<std::string> getHighScore();
	void getUserStatistics(std::vector<std::string>& userStatistics, std::string username);

private:
	static StatisticsManager* instancePtr;
	IDatabase* m_database;
	StatisticsManager();
};

