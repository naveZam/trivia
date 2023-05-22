#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"
#include "Singleton.h"
#include <WinSock2.h>
#include <Windows.h>
#include <map>

class Communicator
{
	MAKE_SINGLETON_CLASS(Communicator);

public:
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET clientSocket);

	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
};

