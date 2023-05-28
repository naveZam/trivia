#pragma once
#include <string>
class Question
{
public:
	Question(int id, std::string question, std::string correctAnswer, std::string answer2, std::string answer3, std::string answer4);
	int getId();
	std::string getQuestion();
	std::string getCorrectAnswer();
	std::string getAnswer2();
	std::string getAnswer3();
	std::string getAnswer4();
private:
	int _id;
	std::string _question;
	std::string _correctAnswer;
	std::string _answer2;
	std::string _answer3;
	std::string _answer4;
};

