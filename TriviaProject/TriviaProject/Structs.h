#pragma once

struct LoginRequest
{
	std::string username;
	std::string password;
};

struct SignupRequest
{
	std::string username;
	std::string password;
	std::string email;
};

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