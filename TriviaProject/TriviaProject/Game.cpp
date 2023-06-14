#include "Game.h"
int Game::m_gameId = 0;

Game::Game(std::vector<Question> questions, std::map<LoggedUser, GameData> players)
{
    m_questions = questions;
    m_players = players;
    m_gameId++;
}

Question Game::getQuestionForUser(LoggedUser user)
{
    for (auto it = m_players.begin(); it != m_players.end(); it++)
    {
        LoggedUser currUser = it->first;
        if (currUser.getUsername() == user.getUsername())
        {
            return it->second.currentQuestion;
        }
    }
}

void Game::submitAnswer(LoggedUser user, int ansId)
{
    for (auto it = m_players.begin(); it != m_players.end(); it++)
    {
        LoggedUser currUser = it->first;
        if (currUser.getUsername() == user.getUsername())
        {
            if (it->second.currentQuestion.getCorrectAnswerId() == ansId)
            {
                it->second.correctAnswerCount++;
            }
            else
            {
                it->second.wrongAnswerCount++;
            }

            it->second.currentQuestion = this->m_questions.at(currentQuestion);
            currentQuestion++;
        }
    }
}

void Game::removePlayer(LoggedUser user)
{
    for (auto it = m_players.begin(); it != m_players.end(); it++)
    {
        LoggedUser currUser = it->first;
        if (currUser.getUsername() == user.getUsername())
        {
            this->m_players.erase(it);
        }
    }
}
