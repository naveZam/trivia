#pragma once
#include "IRequestHandler.h"
#include "RequestHandlerFactory.h"

#include <WinSock2.h>
#include <Windows.h>
#include <map>

class Communicator
{
public:
	Communicator& operator=(const Communicator&) = delete;
	Communicator(const Communicator& obj) = delete;
	~Communicator();
	void startHandleRequests();
	static Communicator* getInstance();

private:
	Communicator();
	static Communicator* instancePtr;
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET clientSocket);
	SOCKET m_serverSocket;
	std::map<SOCKET, IRequestHandler*> m_clients;
};

