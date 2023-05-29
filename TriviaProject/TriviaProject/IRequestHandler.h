#pragma once
#include <time.h>
#include <vector>
enum requestCodes { LogInRequest = 1, SignUpRequest = 2, CloseRoomRequest = 3, StartGameRequest = 4, GetRoomStateRequest = 5, LeaveRoomRequest = 6, RoomAdminRequest = 420};
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