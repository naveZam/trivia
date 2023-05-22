#pragma once

#include "Communicator.h"
#include "RequestHandlerFactory.h"
#include "Singleton.h"
#include <WinSock2.h>
#include <Windows.h>


class Server
{
	MAKE_SINGLETON_CLASS(Server);
	void run();
	Communicator m_communicator;
};

