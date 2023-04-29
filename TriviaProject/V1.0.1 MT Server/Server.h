#pragma once

#include <WinSock2.h>
#include <Windows.h>


class Server
{
public:
	Server();
	~Server();
	void serve(int port);

private:

	void bindAndListen(int port);
	void acceptClient();
	void clientHandler(SOCKET clientSocket);

	SOCKET _serverSocket;
};

