#include "RequestHandlerFactory.h"

RequestHandlerFactory::RequestHandlerFactory(IDatabase* database, RoomManager roomManager, StatisticsManager statisticsManager) : m_loginManager(database), m_roomManager(roomManager), m_StatisticsManager(statisticsManager)
{
    this->m_database = database;
}

LoginRequestHandler* RequestHandlerFactory::createLoginRequestHandler()
{
    return new LoginRequestHandler(*this);
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
    return m_loginManager;
}
