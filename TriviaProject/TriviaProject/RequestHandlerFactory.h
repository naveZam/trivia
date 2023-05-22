#pragma once
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "StatisticsManager.h"
#include "RoomManager.h"
#include "Singleton.h"

class MenuRequestHandler;
class LoginRequestHandler;

class RequestHandlerFactory
{
	MAKE_SINGLETON_CLASS(RequestHandlerFactory)

public:
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);
	StatisticsManager& getStatisticsManager();
	RoomManager& getRoomManager();
	LoginManager& getLoginManager();

private:
	RoomManager m_roomManager;
	StatisticsManager m_StatisticsManager;
};

