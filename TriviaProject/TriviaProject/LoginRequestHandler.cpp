#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

#include "bitset"
#include <vector>

#define LOG_IN_REQUEST 1
#define SIGN_UP_REQUEST 2



LoginRequestHandler::LoginRequestHandler()
{
}

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LOG_IN_REQUEST || info.id == SIGN_UP_REQUEST)
        return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new LoginRequestHandler();

	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;

	switch(info.id)
	{
	case LOG_IN_REQUEST:
		if (login(info).response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		}
		break;

	case SIGN_UP_REQUEST:
		if (signup(info).response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(SignupRes);
		}
		break;

	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	std::string binaryString = "";

	for (char c : Respones) 
	{
		std::bitset<8> bits(static_cast<unsigned char>(c));
		binaryString += bits.to_string();
	}

	std::vector<unsigned char> binaryChars(binaryString.begin(), binaryString.end());

	result.response = binaryChars;
	return result;
}

RequestResult LoginRequestHandler::login(RequestInfo info)
{
	RequestResult result;
	std::string respond = "";
	LoginRequest user = JsonRequestPacketDeserializer::deserializeLoginRequest(info.buffer);
	LoginManager loginManager;
	loginManager.login(user.username, user.password);

	//make sure the user logged
	if (loginManager.isUserLogged(user.username))
	{
		std::cout << "User successfully logged" << std::endl;
		respond = "1";
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());

	return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo info)
{
	LoginManager loginManager;
	RequestResult result;
	std::string respond = "";
	SignupRequest user = JsonRequestPacketDeserializer::deserializeSignupRequest(info.buffer);

	loginManager.signup(user.username, user.password, user.email);

	//make sure the user logged
	if (loginManager.isUserLogged(user.username))
	{
		std::cout << "User successfully logged" << std::endl;
		respond = "1";
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());

	return result;
}
