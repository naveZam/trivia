#include "SqliteDataBase.h"

SqliteDataBase::SqliteDataBase()
{
	open();
}

bool SqliteDataBase::open()
{
	if (sqlite3_open(DATABASE_NAME, &db) == SQLITE_OK)
	{
		//create table if it doesn't exist
		std::string sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT, email TEXT);";
		sql += "CREATE TABLE IF NOT EXISTS questions (id INTEGER PRIMARY KEY AUTOINCREMENT, question TEXT, correct_ans TEXT, ans2 TEXT, ans3 TEXT, ans4 TEXT);";
		sqlite3_stmt* stmt;
		if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
		{
			if (sqlite3_step(stmt) == SQLITE_DONE)
			{
				return true;
			}
		}
	}
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

Question SqliteDataBase::getQuestions(int questionsNo)
{
	std::string sql = "SELECT * FROM questions WHERE id = " + std::to_string(questionsNo) + ";";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			//get the question and answers from the database
			std::string question = (char*)sqlite3_column_text(stmt, 1);
			std::string correct_ans = (char*)sqlite3_column_text(stmt, 2);
			std::string ans2 = (char*)sqlite3_column_text(stmt, 3);
			std::string ans3 = (char*)sqlite3_column_text(stmt, 4);
			std::string ans4 = (char*)sqlite3_column_text(stmt, 5);
			//create a question object
			Question q(questionsNo, question, correct_ans, ans2, ans3, ans4);
			return q;
		}
	}
}

float SqliteDataBase::getAverageAnswerTime()
{
	return 0.0f;
}

int SqliteDataBase::getNumOfCorrectAnswers()
{
	return 0;
}

int SqliteDataBase::getNumOfTotalAnswers()
{
	return 0;
}

int SqliteDataBase::getNumOfPlayerGames()
{
	return 0;
}

int SqliteDataBase::getPlayerScore()
{
	return 0;
}

std::vector<std::string> SqliteDataBase::getBestScores()
{
	return std::vector<std::string>();
}
