#pragma comment (lib, "ws2_32.lib")

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
		WSAInitializer wsa_init;
		Server md_server;
		md_server.serve(8876);
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