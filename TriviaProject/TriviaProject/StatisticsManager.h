#pragma once
#include <vector>
#include <iostream>

#include "SqliteDataBase.h"

class RequestHandlerFactory;
class LoginRequestHandler;

class StatisticsManager
{
public:
	StatisticsManager(IDatabase* database);
	std::vector<std::string> getHighScore();
	void getUserStatistics(std::vector<std::string>& userStatistics, std::string username);

private:
	IDatabase* m_database;
};

