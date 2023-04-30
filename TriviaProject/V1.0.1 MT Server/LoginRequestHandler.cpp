#include "LoginRequestHandler.h"
#include "JsonResponsePacketSerializer.h"

#include "bitset"

#define LOG_IN_REQUEST 1
#define SIGN_UP_REQUEST 2

bool LoginRequestHandler::isRequestRelevant(RequestInfo info)
{
    if (info.id == LOG_IN_REQUEST || info.id == SIGN_UP_REQUEST)
        return true;
    return false;
}

RequestResult LoginRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result;
	result.newHandler = new LoginRequestHandler;

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	std::string Respones;

	switch(info.id)
	{
	case LOG_IN_REQUEST:
		Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		break;

	case SIGN_UP_REQUEST:
		Respones = JsonResponsePacketSerializer::serializeResponse(SignupRes);
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
