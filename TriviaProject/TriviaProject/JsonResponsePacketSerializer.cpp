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

std::string JsonResponsePacketSerializer::serializeResponse(LogoutResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetRoomsResponse response)
{
	return std::string();
}

std::string JsonResponsePacketSerializer::serializerResponse(GetPlayersInRoomResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(JoinRoomResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(CreateRoomResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(getHighScoreResponse response)
{
	return std::string();
}

std::string JsonResponsePacketSerializer::serializeResponse(getPersonalStatsResponse response)
{
	return std::string();
}
