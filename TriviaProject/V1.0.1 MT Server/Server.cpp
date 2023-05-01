#include "Server.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

Server::Server(RequestHandlerFactory& handlerFactory) : m_communicator(handlerFactory)
{
}

Server::~Server()
{
}

void Server::run()
{
	std::thread tr(&Communicator::startHandleRequests, m_communicator);
	tr.detach();

	std::string adminString = "";

	while (adminString != "EXIT")
	{
		std::cin >> adminString;
	}
}


