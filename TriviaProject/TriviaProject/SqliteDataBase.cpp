#include "SqliteDataBase.h"
SqliteDataBase* SqliteDataBase::instancePtr = NULL;
SqliteDataBase::SqliteDataBase()
{
	open();
}

SqliteDataBase* SqliteDataBase::getInstance()
{
	if (instancePtr == NULL)
	{
		instancePtr = new SqliteDataBase();
	}
	return instancePtr;
}

bool SqliteDataBase::open()
{
	if (sqlite3_open(DATABASE_NAME, &db) == SQLITE_OK)
	{
		//create table if it doesn't exist
		std::string sql = "CREATE TABLE IF NOT EXISTS users (id INTEGER PRIMARY KEY AUTOINCREMENT, username TEXT, password TEXT, email TEXT);";
		sql += "CREATE TABLE IF NOT EXISTS questions (id INTEGER PRIMARY KEY AUTOINCREMENT, question TEXT, correct_ans TEXT, ans2 TEXT, ans3 TEXT, ans4 TEXT);";
		sql += "CREATE TABLE IF NOT EXISTS stats (id INTEGER PRIMARY KEY AUTOINCREMENT, user_id INTEGER, score INTEGER, time INTEGER, answers INTEGER, correct_answers INTEGER, FOREIGN KEY(user_id) REFERENCES users(id));";
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
	//update statistics
	
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

float SqliteDataBase::getAverageAnswerTime(std::string name)
{
	std::string sql = "SELECT AVG(time) FROM stats WHERE user_id = (SELECT id FROM users WHERE username = '" + name + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return sqlite3_column_double(stmt, 0);
		}
	}
}

int SqliteDataBase::getNumOfCorrectAnswers(std::string name)
{
	std::string sql = "SELECT SUM(correct_answers) FROM stats WHERE user_id = (SELECT id FROM users WHERE username = '" + name + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return sqlite3_column_int(stmt, 0);
		}
	}
}

int SqliteDataBase::getNumOfTotalAnswers(std::string name)
{
	std::string sql = "SELECT SUM(answers) FROM stats WHERE user_id = (SELECT id FROM users WHERE username = '" + name + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return sqlite3_column_int(stmt, 0);
		}
	}
}

int SqliteDataBase::getNumOfPlayerGames(std::string name)
{
	std::string sql = "SELECT COUNT(*) FROM stats WHERE user_id = (SELECT id FROM users WHERE username = '" + name + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return sqlite3_column_int(stmt, 0);
		}
	}
}

int SqliteDataBase::getPlayerScore(std::string name)
{
	std::string sql = "SELECT SUM(score) FROM stats WHERE user_id = (SELECT id FROM users WHERE username = '" + name + "');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_ROW)
		{
			return sqlite3_column_int(stmt, 0);
		}
	}
}

std::vector<std::string> SqliteDataBase::getBestScores()
{
	std::string sql = "SELECT username, SUM(score) FROM stats JOIN users ON stats.user_id = users.id GROUP BY username ORDER BY SUM(score) DESC LIMIT 5;";
	sqlite3_stmt* stmt;
	std::vector<std::string> bestScores;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		while (sqlite3_step(stmt) == SQLITE_ROW)
		{
			std::string username = (char*)sqlite3_column_text(stmt, 0);
			std::string score = std::to_string(sqlite3_column_int(stmt, 1));
			bestScores.push_back(username + " " + score);
		}
	}
	return bestScores;
}

void SqliteDataBase::addGame(int id, std::string name, int correctAnswers, int wrongAnswers, float averageAnswerTime, int score)
{
	std::string sql = "INSERT INTO stats (user_id, correct_answers, answers, time, score) VALUES (" + std::to_string(id) + ", " + std::to_string(correctAnswers) + ", " + std::to_string(correctAnswers + wrongAnswers) + ", " + std::to_string(averageAnswerTime) + ", " + std::to_string(score) + ");";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_DONE)
		{
			std::cout << "Game added successfully" << std::endl;
		}
	}
}

void SqliteDataBase::addQuestions()
{
	//add 5 questions
	std::string sql = "INSERT INTO questions (question, correct_ans, ans2, ans3, ans4) VALUES ('What is the username of nave in minecraft?', 'SonicFanGirl01', 'SonicFanGirl', 'TheFakeOri', 'xXIAmAGayFemBoyXx');";
	sql += "INSERT INTO questions (question, correct_ans, ans2, ans3, ans4) VALUES ('How many grains of sand is there?', '7.5 sextillion', '7.4 sextillion', '3', '8 sextillion');";
	sql += "INSERT INTO questions (question, correct_ans, ans2, ans3, ans4) VALUES ('If you pick an answer to this question at random, what is the chance that you will be correct?', '50%', '25%', '25%', '60%');";
	sql += "INSERT INTO questions (question, correct_ans, ans2, ans3, ans4) VALUES ('How long would it take you to die after getting stabbed in the abdomen?', 'couple days', '30 minutes', '1 hour', '5 hours');";
	sql += "INSERT INTO questions (question, correct_ans, ans2, ans3, ans4) VALUES ('What are the chances that you will die from cancer?', '16%', '15%', '20%', '5%');";
	sqlite3_stmt* stmt;
	if (sqlite3_prepare_v2(db, sql.c_str(), -1, &stmt, NULL) == SQLITE_OK)
	{
		if (sqlite3_step(stmt) == SQLITE_DONE)
		{
			std::cout << "Questions added successfully" << std::endl;
		}
	}
}
