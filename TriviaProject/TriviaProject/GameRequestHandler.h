#pragma once
#include "IRequestHandler.h"

class GameRequestHandler : public IRequestHandler
{
public:
	bool isRequestRelevant(RequestInfo info);
	RequestResult handleRequest(RequestInfo info);

private:
	RequestResult getQuestion(RequestInfo info);
	RequestResult submitAnswer(RequestInfo info);
	RequestResult getGameResults(RequestInfo info);
	RequestResult leaveGame(RequestInfo info);

};

