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
	RequestHandlerFactory(const RequestHandlerFactory&) = delete;
	RequestHandlerFactory& operator=(const RequestHandlerFactory&) = delete;
	static RequestHandlerFactory* getInstance();
	RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);


private:
	static RequestHandlerFactory* instancePtr;

	


};

