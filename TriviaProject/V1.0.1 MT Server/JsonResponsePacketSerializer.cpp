#include "JsonResponsePacketSerializer.h"

std::string JsonResponsePacketSerializer::serializeResponse(ErrorResponse errorResponse)
{
	nlohmann::json j;
	j["message"] = errorResponse.message;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(LoginResponse loginResponse)
{
	nlohmann::json j;
	j["status"] = loginResponse.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(SignupResponse signupResponse)
{
	nlohmann::json j;
	j["status"] = signupResponse.status;
	return j.dump();
}
