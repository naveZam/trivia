#include "LoginManager.h"

LoginManager::LoginManager(IDatabase* database)
{
	this->m_database = database;
}

void LoginManager::signup(std::string username, std::string password, std::string email)
{
	this->m_database->addNewUser(username, password, email);
}

void LoginManager::login(std::string username, std::string password)
{
	if(this->m_database->doesPasswordMatch(username, password));
		this->m_loggedUsers.push_back(LoggedUser(username));
	
}

void LoginManager::logout(std::string username)
{
	for (int i = 0; i < this->m_loggedUsers.size(); i++)
	{
		if (this->m_loggedUsers[i].getUsername() == username)
		{
			this->m_loggedUsers.erase(this->m_loggedUsers.begin() + i);
			break;
		}
	}
}

bool LoginManager::isUserLogged(std::string username)
{
	if (m_database->doesUserExist(username))
		return true;
	return false;
}
