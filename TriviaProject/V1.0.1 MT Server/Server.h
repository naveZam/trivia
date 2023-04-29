#pragma once

#include "Communicator.h"
#include <WinSock2.h>
#include <Windows.h>


class Server
{
public:
	Server();
	~Server();
	void run();

private:
	Communicator m_communicator;
};

