#pragma once

#include "GameManager.h"
#include "RoomManager.h"
#include "IRequestHandler.h"
#include "JsonResponsePacketSerializer.h"
#include "JsonRequestPacketDeserializer.h"

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

	Game& m_game;
	LoggedUser m_user;
	GameManager& m_gameManager;

};

