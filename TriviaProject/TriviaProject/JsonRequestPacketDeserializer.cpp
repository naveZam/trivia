#include "JsonRequestPacketDeserializer.h"
#include <bitset>

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> buffer)
{
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to LoginRequest
	LoginRequest loginRequest;
	loginRequest.username = j["username"];
	loginRequest.password = j["password"];
	return loginRequest;

}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> buffer)
{
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	SignupRequest signupRequest;
	signupRequest.username = j["username"];
	signupRequest.password = j["password"];
	signupRequest.email = j["mail"];
	return signupRequest;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersRequest(std::vector<unsigned char> buffer)
{
	return GetPlayersInRoomRequest();
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(std::vector<unsigned char> buffer)
{
	return JoinRoomRequest();
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(std::vector<unsigned char> buffer)
{
	return CreateRoomRequest();
}
