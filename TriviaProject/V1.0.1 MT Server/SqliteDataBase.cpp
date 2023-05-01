#include "SqliteDataBase.h"

SqliteDataBase::SqliteDataBase()
{
	open();
}

bool SqliteDataBase::open()
{
	if (sqlite3_open(DATABASE_NAME, &db) == SQLITE_OK)
	{
		return true;
	}
	return false;
}

bool SqliteDataBase::close()
{
	if (sqlite3_close(db) == SQLITE_OK)
	{
		return true;
	}
	return false;
}

int SqliteDataBase::doesUserExist(std::string username)
{
	std::string sql = "SELECT * FROM users WHERE username = '" + username + "';";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return 1;
		}
	}
	return 0;
}

int SqliteDataBase::doesPasswordMatch(std::string username, std::string password)
{
	std::string sql = "SELECT * FROM users WHERE username = '" + username + "' AND password = '" + password + "';";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return 1;
		}
	}
	return 0;
}

int SqliteDataBase::addNewUser(std::string username, std::string password, std::string email)
{
	std::string sql = "INSERT INTO users (username, password, email) VALUES ('" + username + "', '" + password + "', '" + email + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_DONE)
		{
			return 1;
		}
	}
	return 0;
}
