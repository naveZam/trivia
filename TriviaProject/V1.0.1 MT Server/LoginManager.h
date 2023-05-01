#pragma once
#include "LoggedUser.h"
#include "SqliteDataBase.h"
#include <vector>

class LoginManager
{
public:
	LoginManager() = default;
	LoginManager(IDatabase* database);
	void signup(std::string username, std::string password, std::string email);
	void login(std::string username, std::string password);
	void logout(std::string username);
	bool isUserLogged(std::string username);

private:
	IDatabase* m_database;
	std::vector<LoggedUser> m_loggedUsers;
};

