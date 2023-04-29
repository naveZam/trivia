#include "Communicator.h"
#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

// using static const instead of macros 
static const unsigned short PORT = 69420;

Communicator::Communicator()
{
	// this server use TCP. that why SOCK_STREAM & IPPROTO_TCP
	// if the server use UDP we will use: SOCK_DGRAM & IPPROTO_UDP
	m_serverSocket = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	if (m_serverSocket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__ " - socket");
}

Communicator::~Communicator()
{
	try
	{
		// the only use of the destructor should be for freeing 
		// resources that was allocated in the constructor
		closesocket(m_serverSocket);
	}
	catch (...) {}
}

void Communicator::startHandleRequests()
{
	bindAndListen();

	// create new thread for handling message
	//std::thread tr(&Server::handleReceivedMessages, this);
	//tr.detach();

	while (true)
	{
		// the main thread is only accepting clients 
		// and add then to the list of handlers
		std::cout << "Waiting for client connection request..." << std::endl;
		acceptClient();
	}
}

void Communicator::bindAndListen()
{
	struct sockaddr_in sa = { 0 };

	sa.sin_port = htons(PORT);
	sa.sin_family = AF_INET;
	sa.sin_addr.s_addr = INADDR_ANY;

	// again stepping out to the global namespace
	if (::bind(m_serverSocket, (struct sockaddr*)&sa, sizeof(sa)) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - bind");
	std::cout << "binded" << std::endl;

	if (::listen(m_serverSocket, SOMAXCONN) == SOCKET_ERROR)
		throw std::exception(__FUNCTION__ " - listen");
	std::cout << "listening..." << std::endl;
}

void Communicator::acceptClient()
{
	SOCKET client_socket = accept(m_serverSocket, NULL, NULL);
	if (client_socket == INVALID_SOCKET)
		throw std::exception(__FUNCTION__);

	std::cout << "Client accepted !" << std::endl;

	// create new thread for client	and detach from it
	std::thread tr(&Communicator::handleNewClient, this, client_socket);
	tr.detach();
}

void Communicator::handleNewClient(SOCKET clientSocket)
{
	try
	{
		std::string s = "Hello";
		send(clientSocket, s.c_str(), s.size(), 0);  // last parameter: flag. for us will be 0.

		char m[6];
		recv(clientSocket, m, 5, 0);
		m[5] = 0;
		std::cout << "Client message is: " << m << std::endl;

		// Closing the socket (in the level of the TCP protocol)
		closesocket(clientSocket);
	}
	catch (const std::exception& e)
	{
		closesocket(clientSocket);
	}
}
