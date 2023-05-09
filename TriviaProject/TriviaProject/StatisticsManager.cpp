#include "StatisticsManager.h"

std::vector<std::string> StatisticsManager::getHighScore()
{
    return m_database->getBestScores();
}

void StatisticsManager::getUserStatistics(std::vector<std::string>& userStatistics, std::string username)
{
    userStatistics.push_back(std::to_string(m_database->getAverageAnswerTime(username)));
    userStatistics.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
    userStatistics.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));
    userStatistics.push_back(std::to_string(m_database->getNumOfTotalAnswers(username)));
    userStatistics.push_back(std::to_string(m_database->getPlayerScore(username)));
}
