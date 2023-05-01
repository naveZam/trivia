#include "Server.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

Server::Server(RequestHandlerFactory& handlerFactory, IDatabase* database) : m_communicator(handlerFactory, database), m_handlerFactory(handlerFactory)
{
	this->m_database = database;
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


