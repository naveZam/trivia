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

std::string JsonResponsePacketSerializer::serializeResponse(GetPlayersInRoomResponse response)
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
	std::string scores = "";
	nlohmann::json j;

	for (auto it = response.statistics.begin(); it != response.statistics.end(); it++)
	{
		usersStats += it->at(0);
		usersStats += ", ";

		usersStats += it->at(1);
		usersStats += ", ";

		usersStats += it->at(2);
		usersStats += ", ";

		usersStats += it->at(3);

		scores += it->at(4);
		scores += ", ";
	}

	j["UserStatistics"] = usersStats;
	j["HighScores"] = scores;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(getPersonalStatsResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	j["correctAnswerCount"] = response.statistics.at(0);
	j["totalAnswerCount"] = response.statistics.at(1);
	j["totalGames"] = response.statistics.at(2);
	j["averageAnswerTime"] = response.statistics.at(3);
	return j;
}

std::string JsonResponsePacketSerializer::serializeResponse(CloseRoomResponce response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(StartGameResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetRoomStateResponse response)
{
	nlohmann::json j;
	std::string players;
	j["status"] = response.status;
	j["hasGameBegun"] = response.hasGameBegun;

	for (auto it = response.players.begin(); it != response.players.end(); it++)
	{
		players += ",";
		players += it->at(0);
	}

	j["players"] = players;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(LeaveRoomResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

std::string serializePlayer(PlayerResults response)
{
	nlohmann::json j;

	j["username"] = response.username;
	j["averageAnswerTime"] = response.averageAnswerTime;
	j["correctAnswerCount"] = response.correctAnswerCount;
	j["wrongAnswerCount"] = response.wrongAnswerCount;

	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetGameResultsResponse response)
{
	nlohmann::json j;

	std::string results;
	j["status"] = response.status;

	for (auto it = response.results.begin(); it != response.results.end(); it++)
	{
		results += serializePlayer(*it);
		results += ", ";
	}

	j["results"] = results;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(SubmitAnswerResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	j["correctAnswerId"] = response.correctAnswerId;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(GetQuestionResponse response)
{
	nlohmann::json j;
	std::string answers;
	j["status"] = response.status;
	j["question"] = response.question;

	for (auto it = response.answers.begin(); it != response.answers.end(); it++)
	{
		answers += it->first + ": ";
		answers += '"' + it->second + '"';
		answers += ", ";
	}

	j["answers"] = answers;
	return j.dump();
}

std::string JsonResponsePacketSerializer::serializeResponse(LeaveGameResponse response)
{
	nlohmann::json j;
	j["status"] = response.status;
	return j.dump();
}

