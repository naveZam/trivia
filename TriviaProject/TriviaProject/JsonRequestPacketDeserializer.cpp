#include "JsonRequestPacketDeserializer.h"

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
	SignupRequest signupRequest;
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	signupRequest.username = j["username"];
	signupRequest.password = j["password"];
	signupRequest.email = j["email"];
	return signupRequest;
}

GetPlayersInRoomRequest JsonRequestPacketDeserializer::deserializeGetPlayersRequest(std::vector<unsigned char> buffer)
{
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	GetPlayersInRoomRequest getPlayersInRoomRequest;
	getPlayersInRoomRequest.roomId = j["roomId"];

	return getPlayersInRoomRequest;
}

JoinRoomRequest JsonRequestPacketDeserializer::deserializeJoinRoomRequest(std::vector<unsigned char> buffer)
{
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	JoinRoomRequest joinRoomRequest;
	joinRoomRequest.roomId = j["roomId"];

	return joinRoomRequest;
}

CreateRoomRequest JsonRequestPacketDeserializer::deserializeCreateRoomRequest(std::vector<unsigned char> buffer)
{
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);	

	//sorting the info to SignupRequest
	CreateRoomRequest createRoomRequest;

	createRoomRequest.answerTimeout = j["answerTimeout"];
	createRoomRequest.maxUsers = j["maxUsers"];
	createRoomRequest.questionCount = j["questionCount"];
	createRoomRequest.roomName = j["roomName"];

	return createRoomRequest;
}

SubmitAnswerRequest JsonRequestPacketDeserializer::deserializeSubmitAnswerRequest(std::vector<unsigned char> buffer)
{
	//parsing the info
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	SubmitAnswerRequest submitAnswerRequest;

	submitAnswerRequest.answerId = j["answerId"];

	return submitAnswerRequest;
}

RoomData JsonRequestPacketDeserializer::deserializeRoomData(std::vector<unsigned char> buffer)
{
	//parsing the info
	RoomData roomData;
	nlohmann::json j = nlohmann::json::parse(buffer);

	//sorting the info to SignupRequest
	

	roomData.name = j["roomName"];
	roomData.numOfQuestionsInGame = j["questionCount"];
	roomData.maxPlayers = j["maxPlayers"];
	roomData.timePerQuestion = j["answerTimeout"];
	

	return roomData;
}
