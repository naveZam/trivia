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
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(logoutRes);
		}
		break;
	case GetRoomsRequest:
		result = getRooms(info);
		
		if (result.response == error)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(transformToRooms(result));
		}
		break;
	case GetPlayersInRoomRequestCode:
		result = getPlayersInRoom(info);
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(transformToPlayers(result));
		}
		break;
	case JoinRoomRequestCode:
		result = joinRoom(info);
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		}
		break;
	case CreateRoomRequestCode:
		result = createRoom(info);
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(loginRes);
		}
		break;
	case getHighScoreResponseCode:
		result = getHighScore(info);
		if (result.response != nonError)
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
		}
		else
		{
			Respones = JsonResponsePacketSerializer::serializeResponse(transformToScore(result));
		}
		break;
	case GetPersonalStatsRequest:
		result = getPersonalStats(info);
		break;
	default:
		Respones = JsonResponsePacketSerializer::serializeResponse(ErrorRes);
	}

	//result.response = std::vector<unsigned char>(Respones.begin(), Respones.end());
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
	RoomManager* manager = RoomManager::getInstance();
	std::vector<RoomData> data = manager->getRooms();
	for (RoomData& room : data)
	{
		result.response.push_back(room.id);
	}
	return result;
}

RequestResult MenuRequestHandler::getPlayersInRoom(RequestInfo info)
{
	RequestResult result;
	RoomManager* manager = RoomManager::getInstance();
	std::string respond = "";
	std::vector<RoomData> data = manager->getRooms();
	std::string text;
	int roomID = 0;
	for (int i = 0; i < info.buffer.size(); i++)
	{
		roomID *= 10;
		roomID += info.buffer[i];
	}
	std::vector<std::string> temp = manager->getRoom(roomID).getAllUsers();
	for (std::string& user : temp)
	{
		respond += user + ",";
	}
	respond.pop_back();
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getPersonalStats(RequestInfo info)
{
	RequestResult result;
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
	int roomID = 0;
	for (int i = 0; i < info.buffer.size(); i++)
	{
		roomID *= 10;
		roomID += info.buffer[i];
	}
	manager->getRoom(roomID).addUser(m_user.getUsername());
	delete result.newHandler;
	result.newHandler = RequestHandlerFactory::getInstance()->createRoomMemberRequestHandler(m_user, manager->getRoom(roomID));
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::createRoom(RequestInfo info)
{
	RequestResult result;
	RoomManager* manager = RoomManager::getInstance();
	std::string respond = "";
	manager->createRoom(m_user.getUsername(), RoomData());
	delete result.newHandler;
	result.newHandler = RequestHandlerFactory::getInstance()->createRoomAdminRequestHandler(m_user, manager->getRoom(manager->getRooms().size()));
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

RequestResult MenuRequestHandler::getHighScore(RequestInfo info)
{
	RequestResult result;
	SqliteDataBase* db = SqliteDataBase::getInstance();
	std::string respond = "";
	std::vector<std::string> data = db->getBestScores();
	for (std::string& score : data)
	{
		respond += score + ",";
	}
	respond.pop_back();
	result.response = std::vector<unsigned char>(respond.begin(), respond.end());
	return result;
}

GetRoomsResponse MenuRequestHandler::transformToRooms(RequestResult info)
{
	GetRoomsResponse response;
	RoomManager* manager = RoomManager::getInstance();
	for(unsigned char id : info.response)
	{
		response.rooms.push_back(manager->getRoom(id).getRoomData());
	}
	return response;
}

GetPlayersInRoomResponse MenuRequestHandler::transformToPlayers(RequestResult info)
{
	GetPlayersInRoomResponse response;
	std::string temp = "";
	for (unsigned char c : info.response)
	{
		if (c == ',')
		{
			response.players.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	return response;
}

getHighScoreResponse MenuRequestHandler::transformToScore(RequestResult info)
{
	getHighScoreResponse response;
	std::string temp = "";
	for (unsigned char c : info.response)
	{
		if (c == ',')
		{
			response.statistics.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	if (temp != "")
		response.statistics.push_back(temp);
	return response;
}

getPersonalStatsResponse MenuRequestHandler::transformToStats(RequestResult info)
{
	getPersonalStatsResponse response;
	std::string temp = "";
	for (unsigned char c : info.response)
	{
		if (c == ',')
		{
			response.statistics.push_back(temp);
			temp = "";
		}
		else
		{
			temp += c;
		}
	}
	return response;
}

