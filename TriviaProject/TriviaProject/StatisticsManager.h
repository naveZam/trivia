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
	std::vector<std::string> getUserStatistics(std::string username);

private:
	IDatabase* m_database;
};

