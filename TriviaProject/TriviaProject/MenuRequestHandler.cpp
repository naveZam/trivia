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
	result.newHandler = new MenuRequestHandler(m_user);

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

RequestResult MenuRequestHandler::signout(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new LoginRequestHandler();
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

RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

RequestResult MenuRequestHandler::getPersonalStats(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

RequestResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

RequestResult MenuRequestHandler::getHighScore(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new MenuRequestHandler(m_user);
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

