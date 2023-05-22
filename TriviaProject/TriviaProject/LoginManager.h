#pragma once
#include "LoggedUser.h"
#include "SqliteDataBase.h"
#include "Singleton.h"
#include <vector>

class LoginManager
{
	MAKE_SINGLETON_CLASS(LoginManager)

public:
	void signup(std::string username, std::string password, std::string email);
	void login(std::string username, std::string password);
	void logout(std::string username);
	bool isUserLogged(std::string username);

private:
	std::vector<LoggedUser> m_loggedUsers;
};

