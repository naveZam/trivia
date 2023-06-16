#include "JsonRequestPacketDeserializer.h"
#include "JsonResponsePacketSerializer.h"
#include "LoginRequestHandler.h"
#include "Communicator.h"

#include <exception>
#include <iostream>
#include <string>
#include <thread>
#include <bitset>
#include <mutex>


#define AMOUNT_OF_SIZE_BYTES 5

#define DISCONNECT_ID 200

Communicator* Communicator::instancePtr = NULL;
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

Communicator* Communicator::getInstance()
{
	if (instancePtr == NULL)
	{
		instancePtr = new Communicator();
	}
	return instancePtr;
}

std::map<SOCKET, IRequestHandler*> Communicator::getClients()
{
	return m_clients;
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

	std::cout << "New Client Connection" << std::endl;

	LoginRequestHandler* newLoginReq = new LoginRequestHandler();

	m_clients.insert(std::pair<SOCKET, IRequestHandler*>(client_socket, newLoginReq));

	// create new thread for client	and detach from it
	std::thread tr(&Communicator::handleNewClient, this, client_socket);
	tr.detach();
}

void sendMessageToUser(SOCKET clientSocket, RequestResult result, int code)
{
	int size = result.response.size();
	std::string sizeBuffer = "";
	int i = 0;

	while (i < AMOUNT_OF_SIZE_BYTES - size)
	{
		sizeBuffer += "0";
		i++;
	}

	sizeBuffer += size;

	std::string message = std::to_string(code) + sizeBuffer + std::string(result.response.begin(), result.response.end());
	send(clientSocket, message.c_str(), message.size(), 0);
}

int strToInt(std::string str)
{
	int i = 0;
	int val = 0;

	for (i = 0; i < str.size(); i++)
	{
		val += str[i] * pow(10, AMOUNT_OF_SIZE_BYTES - i - 1);
	}

	return val;
}

RequestInfo GetMessageInfo(std::vector<unsigned char> buffer, int codeId)
{
	RequestInfo info;
	std::vector<unsigned char> code = std::vector<unsigned char>(buffer.begin(), buffer.begin() + 1);
	std::vector<unsigned char> size = std::vector<unsigned char>(buffer.begin() + 1, buffer.begin() + (AMOUNT_OF_SIZE_BYTES + 1));

	std::string sizeStr = std::string(size.begin(), size.end());
	int sizeOfJson = strToInt(sizeStr);

	std::vector<unsigned char> actualBuffer = std::vector<unsigned char>(buffer.begin() + (AMOUNT_OF_SIZE_BYTES + 1), buffer.begin() + (AMOUNT_OF_SIZE_BYTES + 1) + sizeOfJson);

	//Setup the request's info
	
	info.id = codeId;
	info.buffer = actualBuffer;
	info.receivalTime = std::chrono::system_clock::to_time_t(std::chrono::system_clock::now());

	return info;
}

void Communicator::handleNewClient(SOCKET clientSocket)
{
	try
	{
		int codeId = 0;
		do
		{
			//reseve the request from the client 
			std::vector<unsigned char> buffer(4096);
			std::cout << "new" << std::endl;
			int iResult = 0;
			while (iResult == 0)
			{
				iResult = recv(clientSocket, (char*)buffer.data(), buffer.size(), 0);
				if (iResult == SOCKET_ERROR)
					throw std::exception(__FUNCTION__);
			}
			codeId = getMessageId(buffer);
			RequestInfo info = GetMessageInfo(buffer, codeId);

			IRequestHandler* handler = this->m_clients[clientSocket];

			
			if (!handler->isRequestRelevant(info))
			{
				RequestResult error;
				std::string shem = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
				error.response = std::vector<unsigned char>(shem.begin(), shem.end());
				std::cout << "Request not relevant" << std::endl;
				sendMessageToUser(clientSocket, error, handler->isRequestRelevant(info));
				continue;
			}
			RequestResult result = handler->handleRequest(info);
			delete this->m_clients[clientSocket];
			this->m_clients[clientSocket] = result.newHandler;
			sendMessageToUser(clientSocket, result, 1);
		} while (codeId != DISCONNECT_ID);
		
		// Closing the socket (in the level of the TCP protocol)
		closesocket(clientSocket);
	}
	catch (const std::exception& e)
	{
		closesocket(clientSocket);
	}
}

int Communicator::getMessageId(std::vector<unsigned char> buffer)
{
	return buffer[0];
}
