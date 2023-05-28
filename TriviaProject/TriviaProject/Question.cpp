#include "Question.h"

Question::Question(int id, std::string question, std::string correctAnswer, std::string answer2, std::string answer3, std::string answer4)
{
	this->_id = id;
	this->_question = question;
	this->_correctAnswer = correctAnswer;
	this->_answer2 = answer2;
	this->_answer3 = answer3;
	this->_answer4 = answer4;
}

int Question::getId()
{
	return this->_id;
}

std::string Question::getQuestion()
{
	return this->_question;
}

std::string Question::getCorrectAnswer()
{
	return this->_correctAnswer;
}

std::string Question::getAnswer2()
{
	return this->_answer2;
}

std::string Question::getAnswer3()
{
	return this->_answer3;
}

std::string Question::getAnswer4()
{
	return this->_answer4;
}
