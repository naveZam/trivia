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
	std::string retString = "";
	nlohmann::json j;

	for (auto it = response.rooms.begin(); it != response.rooms.end(); it++)
	{
		retString += it->name;
		retString += ", ";
	}

	j["rooms"] = retString;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializerResponse(GetPlayersInRoomResponse response)
{
	std::string usersString = "";
	nlohmann::json j;

	for (auto it = response.players.begin(); it != response.players.end(); it++)
	{
		usersString += it->c_str();
		usersString += ", ";
	}

	j["PlayersInRoom"] = usersString;
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
	std::string usersStats = "";
	nlohmann::json j;

	for (auto it = response.statistics.begin(); it != response.statistics.end(); it++)
	{
		usersStats;
		usersStats += ", ";
	}
	return std::string();
}