#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "LoginRequestHandler.h"
#include "Communicator.h"

#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <mutex>

#define LOG_IN_REQUEST 1
#define SIGN_UP_REQUEST 2

#define BYTE_SIZE 8
#define AMOUNT_OF_SIZE_BYTES 5

// using static const instead of macros 
static const unsigned short PORT = 42069;

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

	LoginRequestHandler* newLoginReq = new LoginRequestHandler();

	m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, newLoginReq));

	// create new thread for client	and detach from it
	std::thread tr(&Communicator::handleNewClient, this, client_socket);
	tr.detach();
}

int binaryToDecimal(int n)
{
	int dec_value = 0;
	int base = 1;
	int num = n;
	int last_digit = 0;

	int temp = num;
	while (temp) 
	{
		last_digit = temp % 10;
		temp = temp / 10;

		dec_value += last_digit * base;

		base = base * 2;
	}

	return dec_value;
}

void Communicator::handleNewClient(SOCKET clientSocket)
{
	try
	{
		//reseve the request from the client 
		std::vector<unsigned char> buffer(4096);
		int iResult = recv(clientSocket, (char*)buffer.data(), buffer.size(), 0);
		if (iResult == SOCKET_ERROR)
			throw std::exception(__FUNCTION__);
		
		std::vector<unsigned char> code = std::vector<unsigned char>(buffer.begin(), buffer.begin() + BYTE_SIZE);
		std::vector<unsigned char> size = std::vector<unsigned char>(buffer.begin() + BYTE_SIZE, buffer.begin() + BYTE_SIZE * (AMOUNT_OF_SIZE_BYTES + 1));

		std::string codeStr = std::string(code.begin(), code.end());
		int codeId = binaryToDecimal(std::stoi(codeStr));

		std::string sizeStr = std::string(size.begin(), size.end());
		int sizeOfJson = binaryToDecimal(std::stoi(sizeStr));
		std::cout << "size of json: " << sizeOfJson << std::endl;

		std::vector<unsigned char> actualBuffer = std::vector<unsigned char>(buffer.begin() + BYTE_SIZE * (AMOUNT_OF_SIZE_BYTES + 1), buffer.begin() + BYTE_SIZE * (AMOUNT_OF_SIZE_BYTES + 1) + sizeOfJson);

		//Setup the request's info
		RequestInfo info;
		info.id = codeId;
		info.buffer = actualBuffer;
		info.receivalTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

		LoginRequestHandler handler;

		if (!handler.isRequestRelevant(info))
		{
			//TODO: sent error response
			std::cout << "not relevant request" << std::endl;
			closesocket(clientSocket);
			throw std::exception(__FUNCTION__ " - not relevant request");
		}
		RequestResult result = handler.handleRequest(info);
		
		//requests struct type
		LoginRequest login;
		SignupRequest signup;

		switch (codeId)
		{
		case LOG_IN_REQUEST:
			login = JsonRequestPacketDeserializer::deserializeLoginRequest(actualBuffer);
			break;
		case SIGN_UP_REQUEST:
			signup = JsonRequestPacketDeserializer::deserializeSignupRequest(actualBuffer);
			break;
		}

		// Closing the socket (in the level of the TCP protocol)
		closesocket(clientSocket);
	}
	catch (const std::exception& e)
	{
		closesocket(clientSocket);
	}
}
