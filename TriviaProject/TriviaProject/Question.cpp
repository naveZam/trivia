#include "Question.h"

Question::Question(std::string question, std::vector<std::string> possibleAnswers, int correctAnswerId)
{
    m_possibleAnswers = possibleAnswers;
    m_question = question;
    m_correctAnswerId = correctAnswerId;
}

Question::Question()
{

}

std::string Question::getQuestion()
{
    return m_question;
}

std::vector<std::string> Question::getPossibleAnswers()
{
    return m_possibleAnswers;
}

int Question::getCorrectAnswerId()
{
    return m_correctAnswerId;
}
