#pragma once

#include "JsonResponsePacketSerializer.h"
#include "Structs.h"

class JsonRequestPacketDeserializer
{
public:
	static LoginRequest deserializeLoginRequest(std::vector<unsigned char> buffer);
	static SignupRequest deserializeSignupRequest(std::vector<unsigned char> buffer);
};

