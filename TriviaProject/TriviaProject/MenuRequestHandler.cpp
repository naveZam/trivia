#include "MenuRequestHandler.h"

MenuRequestHandler::MenuRequestHandler(LoggedUser user) : m_user(user)
{
}

bool MenuRequestHandler::isRequestRelevant(RequestInfo info)
{
	if (info.id == 69 || info.id == SignOutRequest || info.id == GetRoomsRequest || info.id == GetPlayersInRoomRequestCode || info.id == JoinRoomRequestCode || info.id == CreateRoomRequestCode || info.id == getHighScoreResponseCode || info.id == GetPersonalStatsRequest)
	{
		return true;
	}
	return false;
}

RequestResult MenuRequestHandler::handleRequest(RequestInfo info)
{
	RequestResult result;
	result.newHandler = nullptr;

	std::string notErrorrRespond = "1";
	std::string errorResponse = "0";
	
	std::vector<unsigned char> nonError = std::vector<unsigned char>(notErrorrRespond.begin(), notErrorrRespond.end());
	std::vector<unsigned char> error = std::vector<unsigned char>(errorResponse.begin(), errorResponse.end());

	LoginResponse loginRes;
	SignupResponse SignupRes;
	ErrorResponse ErrorRes;
	LogoutResponse logoutRes;
	GetRoomsResponse getRoomsRes;
	GetPlayersInRoomResponse getPlayersInRoomRes;
	getHighScoreResponse getHighScoreRes;
	std::string Respones;
	switch (info.id)
	{
	case SignOutRequest:
		result = signout(info);
		break;
	case GetRoomsRequest:
		result = getRooms(info);

		break;
	case GetPlayersInRoomRequestCode:
		result = getPlayersInRoom(info);
		break;
	case JoinRoomRequestCode:
		result = joinRoom(info);
		break;
	case CreateRoomRequestCode:
		result = createRoom(info);
		break;
	case getHighScoreResponseCode:
		result = getHighScore(info);
		break;
	case GetPersonalStatsRequest:
		result = getPersonalStats(info);
		break;
	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
	}

	
	return result;
}

RequestResult MenuRequestHandler::signout(RequestInfo info)
{
	RequestResult result;
	LoginManager loginManager;
	std::string respond = "";
	loginManager.logout(m_user.getUsername());
	if (!loginManager.isUserLogged(m_user.getUsername()))
	{
		std::cout << "User successfully unlogged" << std::endl;
		respond = "1";
		delete result.newHandler;
		result.newHandler = nullptr;
	}
	
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getRooms(RequestInfo info)
{
	RequestResult result;
	result.newHandler = nullptr;
	RoomManager* manager = RoomManager::getInstance();
	std::vector<RoomData> data = manager->getRooms();
	GetRoomsResponse getRoomsRes;
	ErrorResponse ErrorRes;
	for (RoomData& room : data)
	{
		getRoomsRes.rooms.push_back(room);
	}
	std::string respond = "";
	try
	{
		respond = JsonResponsePacketSerializer::serializeResponse(getRoomsRes);
	}
	catch (const std::exception&)
	{
		respond = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	RequestResult result;
	result.newHandler = nullptr;
	RoomManager* manager = RoomManager::getInstance();
	ErrorResponse ErrorRes;
	std::string respond = "";
	std::vector<RoomData> data = manager->getRooms();
	nlohmann::json j = nlohmann::json::parse(info.buffer);
	std::string text;
	int roomID = j["roomId"];
	GetPlayersInRoomResponse getPlayersInRoomRes;
	std::vector<std::string> temp = manager->getRoom(roomID).getAllUsers();
	for (std::string& user : temp)
	{
		getPlayersInRoomRes.players.push_back(user);
	}
	try
	{
		respond = JsonResponsePacketSerializer::serializeResponse(getPlayersInRoomRes);
	}
	catch (const std::exception& e)
	{
		ErrorRes.message = "Error: Room has no players";
		respond = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getPersonalStats(RequestInfo info)
{
	RequestResult result;
	result.newHandler = nullptr;
	ErrorResponse ErrorRes;
	getHighScoreResponse getHighScoreRes;
	std::string Respones = "";
	SqliteDataBase* db = SqliteDataBase::getInstance();

	getHighScoreRes.statistics.push_back(std::to_string(db->getNumOfCorrectAnswers(m_user.getUsername())));
	getHighScoreRes.statistics.push_back(std::to_string(db->getNumOfTotalAnswers(m_user.getUsername())));
	getHighScoreRes.statistics.push_back(std::to_string(db->getNumOfPlayerGames(m_user.getUsername())));
	getHighScoreRes.statistics.push_back(std::to_string(db->getAverageAnswerTime(m_user.getUsername())));
	getHighScoreRes.status = 1;


	try 
	{
		Respones = JsonResponsePacketSerializer::serializeResponse(getHighScoreRes);
	}
	catch (const std::exception& e) 
	{
		ErrorRes.message = "Error: User have no statistics";
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}
	//Respones += std::to_string(db->getNumOfCorrectAnswers(m_user.getUsername())) + "," + std::to_string(db->getNumOfTotalAnswers(m_user.getUsername())) + "," + std::to_string(db->getNumOfPlayerGames(m_user.getUsername() + "," + std::to_string(db->getAverageAnswerTime(m_user.getUsername()))));//reminder to maybe add more to here
	
	result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());

	return result;
}

RequestResult MenuRequestHandler::joinRoom(RequestInfo info)
{
	RequestResult result;
	RoomManager* manager = RoomManager::getInstance();
	std::string respond = "";
	std::vector<RoomData> data = manager->getRooms();
	JoinRoomResponse joinRoomRes;
	ErrorResponse ErrorRes;
	nlohmann::json j = nlohmann::json::parse(info.buffer);
	int roomID = j["roomId"];
	try
	{
		manager->getRoom(roomID).addUser(m_user.getUsername());
		result.newHandler = RequestHandlerFactory::getInstance()->createRoomMemberRequestHandler(m_user, manager->getRoom(roomID));
		respond = JsonResponsePacketSerializer::serializeResponse(joinRoomRes);
	}
	catch (const std::exception& e)
	{
		ErrorRes.message = "Error: Room is full";
		respond = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	RequestResult result;
	RoomManager* manager = RoomManager::getInstance();
	std::string respond = "";
	CreateRoomResponse createRoomRes;
	ErrorResponse ErrorRes;
	try
	{
		
		manager->createRoom(m_user.getUsername(), JsonRequestPacketDeserializer::deserializeRoomData(info.buffer));
	}
	catch (const std::exception& e)
	{
		ErrorRes.message = "Error: creating room";
		respond = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}
	result.newHandler = RequestHandlerFactory::getInstance()->createRoomAdminRequestHandler(m_user, manager->getRoom(manager->getRooms().size() - 1));
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getHighScore(RequestInfo info)
{
	RequestResult result;
	result.newHandler = nullptr;
	SqliteDataBase* db = SqliteDataBase::getInstance();
	std::string respond = "";
	std::vector<std::string> data = db->getBestScores();
	getHighScoreResponse getHighScoreRes;
	for (std::string& score : data)
	{
		getHighScoreRes.statistics.push_back(score);
	}
	try
	{
		respond = JsonResponsePacketSerializer::serializeResponse(getHighScoreRes);
	}
	catch (const std::exception& e)
	{
		respond = JsonResponsePacketSerializer::serializeResponse(ErrorResponse());
	}
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

