#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include <WinSock2.h>
#include <Windows.h>


class Server
{
public:
	Server();
	~Server();
	void run();

private:

};

