#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

#include <WinSock2.h>
#include <Windows.h>
#include <map>

class Communicator
{
public:
	Communicator(RequestHandlerFactory& handlerFactory, IDatabase* database);
	~Communicator();
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET clientSocket);

	SOCKET m_serverSocket;
	RequestHandlerFactory& m_handlerFactory;
	std::map<SOCKET, IRequestHandler*> m_clients;
};

