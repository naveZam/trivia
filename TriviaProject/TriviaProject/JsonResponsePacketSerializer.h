#pragma once

#include <iostream>
#include "json.hpp"
#include "Structs.h"

class JsonResponsePacketSerializer
{
public:
	static std::string serializeResponse(ErrorResponse errorResponse);
	static std::string serializeResponse(LoginResponse loginResponse);
	static std::string serializeResponse(SignupResponse signupResponse);

	static std::string serializeResponse(LogoutResponse response);
	static std::string serializeResponse(GetRoomsResponse response);
	static std::string serializeResponse(GetPlayersInRoomResponse response);
	static std::string serializeResponse(JoinRoomResponse response);
	static std::string serializeResponse(CreateRoomResponse response);
	static std::string serializeResponse(getHighScoreResponse response);
	static std::string serializeResponse(getPersonalStatsResponse response);
	static std::string serializeResponse(CloseRoomResponce response);
	static std::string serializeResponse(StartGameResponse response);
	static std::string serializeResponse(GetRoomStateResponse response);
	static std::string serializeResponse(LeaveRoomResponse response);

	static std::string serializeResponse(GetGameResultsResponse response);
	static std::string serializeResponse(SubmitAnswerResponse response);
	static std::string serializeResponse(GetQuestionResponse response);
	static std::string serializeResponse(LeaveGameResponse response);
};