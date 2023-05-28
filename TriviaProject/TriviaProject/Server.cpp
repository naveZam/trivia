#include "Server.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

Server::Server()
{
}

Server::~Server()
{
}

void Server::run()
{
	std::thread tr(&Communicator::startHandleRequests, Communicator::getInstance());
	tr.detach();

	std::string adminString = "";

	while (adminString != "EXIT")
	{
		std::cin >> adminString;
	}
}


