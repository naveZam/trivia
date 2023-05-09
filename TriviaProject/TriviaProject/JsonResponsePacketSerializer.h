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

	/*static std::string serializeResponse(LogoutResponse);
	static std::string serializeResponse(GetRoomsResponse);
	static std::string serializerResponse(GetPlayersInRoomResponse);
	static std::string serializeResponse(JoinRoomResponse);
	static std::string serializeResponse(CreateRoomResponse);
	static std::string serializeResponse(getHighScoreResponse);
	static std::string serializeResponse(getPersonalStatsResponse);*/
};