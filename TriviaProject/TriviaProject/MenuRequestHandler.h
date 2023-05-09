#pragma once
#include "LoginRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "LoggedUser.h"

class MenuRequestHandler
{
public:
	MenuRequestHandler(RequestHandlerFactory& handlerFactory, std::string username, RoomManager roomManage, StatisticsManager manager);
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);


private:
	LoggedUser m_user;
	RoomManager& m_roomManager;
	StatisticsManager& m_statisticsManager;
	RequestHandlerFactory& m_handlerFactory;
};

