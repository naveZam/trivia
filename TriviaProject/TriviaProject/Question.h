#pragma once
#include <iostream>
#include <vector>

class Question
{
public:
	Question(std::string question, std::vector<std::string> possibleAnswers, int correctAnswerId);
	Question();
	std::string getQuestion();
	std::vector<std::string> getPossibleAnswers();
	int getCorrectAnswerId();

private:
	int m_correctAnswerId;
	std::string m_question;
	std::vector<std::string> m_possibleAnswers;
};

