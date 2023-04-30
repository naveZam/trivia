#pragma once

#include <iostream>
#include "json.hpp"

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

class JsonResponsePacketSerializer
{
public:
	static std::string serializeResponse(ErrorResponse errorResponse);
	static std::string serializeResponse(LoginResponse loginResponse);
	static std::string serializeResponse(SignupResponse signupResponse);
};