#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include <WinSock2.h>
#include <Windows.h>


class Server
{
public:
	Server(RequestHandlerFactory& handlerFactory, IDatabase* database);
	~Server();
	void run();

private:
	IDatabase* m_database;
	Communicator m_communicator;
	RequestHandlerFactory m_handlerFactory;
};

