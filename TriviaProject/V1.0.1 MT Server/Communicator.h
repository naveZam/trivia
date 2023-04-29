#pragma once

#include <WinSock2.h>
#include <Windows.h>
#include <map>

class Communicator
{
public:
	Communicator();
	~Communicator();
	void startHandleRequests();

private:
	void bindAndListen();
	void acceptClient();
	void handleNewClient(SOCKET clientSocket);

	SOCKET m_serverSocket;
	//std::map<SOCKET, IRequestHandler*>;
};

