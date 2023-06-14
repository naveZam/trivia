#pragma once
#include <time.h>
#include <vector>

enum requestCodes 
{
	LogInRequest = 1,
	SignUpRequest = 2,
	CloseRoomRequest = 3,
	StartGameRequest = 4,
	GetRoomStateRequest = 5,
	LeaveRoomRequest = 6,
	RoomMemberRequestHandlerCode = 7,
	SignOutRequest = 8,
	GetRoomsRequest = 9,
	GetPlayersInRoomRequestCode = 10,
	GetPersonalStatsRequest = 11,
	JoinRoomRequestCode = 12,
	CreateRoomRequestCode = 13,
	RoomAdminRequest = 420,
	LeaveGameRequestCode = 14,
	GetQuestionRequestCode = 15,
	SubmitAnswerRequestCode = 16,
	GetGameResultRequestCode = 17,
	getHighScoreResponseCode = 18
};

struct RequestInfo
{
	unsigned int id;
	time_t receivalTime;
	std::vector<unsigned char> buffer;
};

struct RequestResult;

class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual RequestResult handleRequest(RequestInfo info) = 0;
};

struct RequestResult
{
	IRequestHandler* newHandler;
	std::vector<unsigned char> response;
};