#pragma once
#include <time.h>
#include <vector>
struct RequestInfo
{
	unsigned int id;
	time_t receivalTime;
	std::vector<unsigned char> buffer;
};
struct RequestResult
{
	IRequestHandler* newHandler;
	std::vector<unsigned char> response;
};
class IRequestHandler
{
public:
	virtual bool isRequestRelevant(RequestInfo info) = 0;
	virtual RequestResult handleRequest(RequestInfo info) = 0;
};

