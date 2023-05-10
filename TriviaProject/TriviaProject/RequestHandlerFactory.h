#pragma once
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "StatisticsManager.h"
#include "RoomManager.h"

class MenuRequestHandler;
class LoginRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(IDatabase* database, RoomManager roomManager, StatisticsManager statisticsManager);
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	LoginManager& getLoginManager();

private:
	LoginManager m_loginManager;
	IDatabase* m_database;

	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;


};

