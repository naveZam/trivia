#include "RequestHandlerFactory.h"

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    return new LoginRequestHandler();
}

MenuRequestHandler* RequestHandlerFactory::createMenuRequestHandler(LoggedUser user)
{
    return new MenuRequestHandler(*this, user.getUsername(), getRoomManager(), getStatisticsManager());
}

StatisticsManager& RequestHandlerFactory::getStatisticsManager()
{
    return m_StatisticsManager;
}

RoomManager& RequestHandlerFactory::getRoomManager()
{
    return m_roomManager;
}

LoginManager& RequestHandlerFactory::getLoginManager()
{
    return LoginManager::getInstance();
}
