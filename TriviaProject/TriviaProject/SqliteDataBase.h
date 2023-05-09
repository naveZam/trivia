#pragma once

#include "IDatabase.h"
#include "sqlite3.h"
#define DATABASE_NAME "database.db"

class SqliteDataBase : public IDatabase
{
public:
	SqliteDataBase();
	~SqliteDataBase();
	virtual bool open();
	virtual bool close();
	virtual int doesUserExist(std::string username);
	virtual int doesPasswordMatch(std::string username, std::string password);
	virtual int addNewUser(std::string username, std::string password, std::string email);

private:
	sqlite3* db;
};

