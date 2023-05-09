#include "StatisticsManager.h"

std::vector<std::string> StatisticsManager::getHighScore()
{
    return m_database->getBestScores();
}

std::vector<std::string> StatisticsManager::getUserStatistics(std::string username)
{
    std::vector<std::string> stats;
    stats.clear();

    stats.push_back(std::to_string(m_database->getAverageAnswerTime(username)));
    stats.push_back(std::to_string(m_database->getNumOfCorrectAnswers(username)));
    stats.push_back(std::to_string(m_database->getNumOfPlayerGames(username)));
    stats.push_back(std::to_string(m_database->getNumOfTotalAnswers(username)));
    stats.push_back(std::to_string(m_database->getPlayerScore(username)));


    return stats;
}
