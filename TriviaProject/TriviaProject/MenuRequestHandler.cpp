#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(LoggedUser user) : m_user(user)
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	if (info.id == 69)
	{
		return true;
	}
	return false;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler();

	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;

	switch (info.id)
	{
	case 69:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	return result;
}
