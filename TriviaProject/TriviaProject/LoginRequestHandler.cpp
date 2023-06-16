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
	std::cout << "handle" << std::endl;

	std::string notErrorrRespond = "1";
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;

	switch(info.id)
	{
	case LOG_IN_REQUEST:
		result = login(info);
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		}
		break;
	
	case SIGN_UP_REQUEST:
		result = signup(info);
		if ( result.response!= nonError)
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

	std::vector<unsigned char> binaryChars(Respones.begin(), Respones.end());

	result.response = binaryChars;
	return result;
}

RequestResult LoginRequestHandler::login(RequestInfo info)
{
	std::cout << "login" << std::endl;
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
		result.newHandler = RequestHandlerFactory::getInstance()->createMenuRequestHandler(LoggedUser(user.username));
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	
	return result;
}

RequestResult LoginRequestHandler::signup(RequestInfo info)
{
	std::cout << "signup" << std::endl;
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
		result.newHandler = RequestHandlerFactory::getInstance()->createMenuRequestHandler(LoggedUser(user.username));
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());

	return result;
}
