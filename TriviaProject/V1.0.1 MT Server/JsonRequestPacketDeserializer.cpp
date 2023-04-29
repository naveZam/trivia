#include "JsonRequestPacketDeserializer.h"

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> buffer)
{
	nlohmann::json j = nlohmann::json::from_bson(buffer);
	LoginRequest loginRequest;
	loginRequest.username = j["username"];
	loginRequest.password = j["password"];
	return loginRequest;

}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> buffer)
{
	nlohmann::json j = nlohmann::json::from_bson(buffer);
	SignupRequest signupRequest;
	signupRequest.username = j["username"];
	signupRequest.password = j["password"];
	signupRequest.email = j["email"];
	return signupRequest;
}
