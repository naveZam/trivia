#pragma once
#include "LoginRequestHandler.h"
#include "RoomManager.h"
#include "StatisticsManager.h"
#include "LoggedUser.h"

class MenuRequestHandler
{
public:
	MenuRequestHandler();
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);


private:
	LoggedUser m_user;

};

