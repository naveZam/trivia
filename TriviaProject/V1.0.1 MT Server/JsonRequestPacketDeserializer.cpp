#include "JsonRequestPacketDeserializer.h"
#include <bitset>

LoginRequest JsonRequestPacketDeserializer::deserializeLoginRequest(std::vector<unsigned char> buffer)
{
	std::string binaryString(buffer.begin(), buffer.end());
	std::bitset<8> bits;
	std::string charString = "";

	//from bits to string
	for (std::size_t i = 0; i < binaryString.size(); i += 8) {
		bits = std::bitset<8>(binaryString.substr(i, 8));
		charString += static_cast<char>(bits.to_ulong());
	}

	//parsing the info
	nlohmann::json j = nlohmann::json::parse(charString);

	//sorting the info to LoginRequest
	LoginRequest loginRequest;
	loginRequest.username = j["username"];
	loginRequest.password = j["password"];
	return loginRequest;

}

SignupRequest JsonRequestPacketDeserializer::deserializeSignupRequest(std::vector<unsigned char> buffer)
{
	std::string binaryString(buffer.begin(), buffer.end());
	std::bitset<8> bits;
	std::string charString = "";

	//from bits to string
	for (std::size_t i = 0; i < binaryString.size(); i += 8) 
	{
		bits = std::bitset<8>(binaryString.substr(i, 8));
		charString += static_cast<char>(bits.to_ulong());
	}

	//parsing the info
	nlohmann::json j = nlohmann::json::parse(charString);

	//sorting the info to SignupRequest
	SignupRequest signupRequest;
	signupRequest.username = j["username"];
	signupRequest.password = j["password"];
	signupRequest.email = j["email"];
	return signupRequest;
}
