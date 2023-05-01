#pragma comment (lib, "ws2_32.lib")

#include "RequestHandlerFactory.h"
#include "WSAInitializer.h"
#include "Server.h"
#include <iostream>
#include <exception>

int main()
{
	try
	{
		std::cout << "Starting..." << std::endl;

		// NOTICE at the end of this block the WSA will be closed 
		RequestHandlerFactory factory;//PAIN
		WSAInitializer wsa_init;
		Server md_server(factory);
		md_server.run();
	}
	catch (const std::exception& e)
	{
		std::cout << "Exception was thrown in function: " << e.what() << std::endl;
	}
	catch (...)
	{
		std::cout << "Unknown exception in main !" << std::endl;
	}
}