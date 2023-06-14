#include "Game.h"

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
