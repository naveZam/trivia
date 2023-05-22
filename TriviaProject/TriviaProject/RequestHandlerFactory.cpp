#include "RequestHandlerFactory.h"

RequestHandlerFactory* RequestHandlerFactory::getInstance()
{
	if (instancePtr == NULL)
	{
		instancePtr = new RequestHandlerFactory();
	}
	return instancePtr;
}

RequestHandlerFactory::RequestHandlerFactory()
{
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    return new LoginRequestHandler();
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser user)
{
    return new MenuRequestHandler();
}


