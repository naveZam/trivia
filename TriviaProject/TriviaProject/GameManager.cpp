#include "GameManager.h"

Game GameManager::createGame(Room room)
{
    std::vector<Question> questions;
    int i = 0;

    for (i = 0; i < 10; i++)
    {
        questions.push_back(SqliteDataBase::getInstance()->getQuestions(i));
    }
    std::vector<std::string> allUsers = room.getAllUsers();
    std::map<LoggedUser, GameData> players;

    GameData data;
    data.currentQuestion = SqliteDataBase::getInstance()->getQuestions(0);

    for (auto it = allUsers.begin(); it != allUsers.end(); it++)
    {
        players[LoggedUser(*it)] = data;
    }

    Game newGame = Game(questions, players);
    this->m_games.insert(this->m_games.end(), newGame);
    return newGame;
}

void GameManager::deleteGame(int gameId)
{
    int i = 0;
    auto it = m_games.begin();
    for (i = 0; i < gameId; i++)
    {
        it++;
    }
    this->m_games.erase(it);
}
