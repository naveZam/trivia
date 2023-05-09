#pragma once
#include <vector>
#include <iostream>

#include "SqliteDataBase.h"

class RequestHandlerFactory;
class LoginRequestHandler;

class StatisticsManager
{
public:
	StatisticsManager();
	std::vector<std::string> getHighScore();
	void getUserStatistics(std::vector<std::string>& userStatistics, std::string username);

private:
	IDatabase* m_database;
};

