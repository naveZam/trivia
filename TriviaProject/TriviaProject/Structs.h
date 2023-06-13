#pragma once
#include <iostream>
#include <map>
#include <vector>

struct LoginRequest
{
	std::string username;
	std::string password;
};

struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
};

struct LoginResponse
{
	unsigned int status = 1;
};

struct SignupResponse
{
	unsigned int status = 1;
};

struct ErrorResponse
{
	std::string message;
};

struct RoomData
{
	unsigned int id;
	std::string name;
	unsigned int maxPlayers;
	unsigned int numOfQuestionsInGame;
	unsigned int timePerQuestion;
	unsigned int isActive;
};

typedef unsigned int roomID;

struct LogoutResponse
{
	unsigned int status = 1;
};

struct GetRoomsResponse
{
	unsigned int status;
	std::vector<RoomData> rooms;
};

struct GetPlayersInRoomResponse //amongus
{
	std::vector<std::string> players;
};

struct getHighScoreResponse
{
	unsigned int status;
	std::vector<std::string> statistics;
};

struct getPersonalStatsResponse
{
	unsigned int status;
	std::vector<std::string> statistics;
};

struct JoinRoomResponse
{
	unsigned int status;
};

struct CreateRoomResponse
{
	unsigned int status;
};

struct GetPlayersInRoomRequest
{
	unsigned int roomId;
};

struct JoinRoomRequest
{
	unsigned int roomId;
};

struct CreateRoomRequest
{
	std::string roomName;
	unsigned int maxUsers;
	unsigned int questionCount;
	unsigned int answerTimeout;
};

struct StartGameResponse
{
	unsigned int status;
};

struct CloseRoomResponce
{
	unsigned int status;
};

struct GetRoomStateResponse
{
	unsigned int status;
	bool hasGameBegun;
	std::vector<std::string> players;
	unsigned int questionCount;
	unsigned int answerTimeOut;
};

struct LeaveRoomResponse
{
	unsigned int status;
};

struct LeaveGameResponse
{
	unsigned int status;
};

struct GetQuestionResponse
{
	unsigned int status;
	std::string question;
	std::map<unsigned int, std::string> answers;
};

struct SubmitAnswerResponse
{
	unsigned int status;
	unsigned int correctAnswerId;
};

struct PlayerResults
{
	std::string username;
	unsigned int correctAnswerCount;
	unsigned int wrongAnswerCount;
	unsigned int averageAnswerTime;
};

struct GetGameResultsResponse
{
	unsigned int status;
	std::vector<PlayerResults> results;
};

struct SubmitAnswerRequest
{
	unsigned int answerId;
};