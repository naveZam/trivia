#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(RequestHandlerFactory& handlerFactory, std::string username, RoomManager roomManage, StatisticsManager manager) : m_handlerFactory(handlerFactory), m_user(username), m_roomManager(roomManage), m_statisticsManager(manager)
{
}
