#pragma once
#include "LoginRequestHandler.h"
#include "MenuRequestHandler.h"
#include "LoginManager.h"
#include "IDatabase.h"
#include "StatisticsManager.h"
#include "RoomManager.h"
#include "RoomAdminRequestHandler.h"
#include "RoomMemberRequestHandler.h"
#include "GameManager.h"

class MenuRequestHandler;
class LoginRequestHandler;
class RoomAdminRequestHandler;

class RequestHandlerFactory
{
public:
	RequestHandlerFactory(const RequestHandlerFactory&) = delete;
	RequestHandlerFactory& operator=(const RequestHandlerFactory&) = delete;
	static RequestHandlerFactory* getInstance();
	RequestHandlerFactory();
	LoginRequestHandler* createLoginRequestHandler();
	MenuRequestHandler* createMenuRequestHandler(LoggedUser user);
	RoomAdminRequestHandler* createRoomAdminRequestHandler(LoggedUser user, Room room);
	RoomMemberRequestHandler* createRoomMemberRequestHandler(LoggedUser user, Room room);

	//GameRequestHandler* createGameRequestHandler(LoggedUser);
	//GameManager& getGameManager;

private:
	static RequestHandlerFactory* instancePtr;
	//GameManager m_gameManager;
	
};

