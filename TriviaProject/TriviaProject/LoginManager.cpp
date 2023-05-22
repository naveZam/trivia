#include "LoginManager.h"

void LoginManager::signup(std::string username, std::string password, std::string email)
{
	if (SqliteDataBase::getInstance().doesUserExist(username))
	{
		std::cout << "User already in" << std::endl;
		return;
	}
	SqliteDataBase::getInstance().addNewUser(username, password, email);
}

void LoginManager::login(std::string username, std::string password)
{
	if (SqliteDataBase::getInstance().doesUserExist(username))
	{
		if (SqliteDataBase::getInstance().doesPasswordMatch(username, password));
		{
			this->m_loggedUsers.push_back(LoggedUser(username));
		}
	}	
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
	if (SqliteDataBase::getInstance().doesUserExist(username))
		return true;
	return false;
}
