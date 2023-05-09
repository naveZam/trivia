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
};