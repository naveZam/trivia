#pragma once
#include <iostream>
#include <vector>
#include "Question.h"
class IDatabase
{
public:
	virtual bool open() = 0;
	virtual bool close() = 0;
	virtual int doesUserExist(std::string username) = 0;
	virtual int doesPasswordMatch(std::string username, std::string password) = 0;
	virtual int addNewUser(std::string username, std::string password, std::string email) = 0;
	virtual Question getQuestions(int questionsNo) = 0;
	virtual float getAverageAnswerTime(std::string name) = 0;
	virtual int getNumOfCorrectAnswers(std::string name) = 0;
	virtual int getNumOfTotalAnswers(std::string name) = 0;
	virtual int getNumOfPlayerGames(std::string name) = 0;
	virtual int getPlayerScore(std::string name) = 0;
	virtual std::vector<std::string> getBestScores() = 0;
};