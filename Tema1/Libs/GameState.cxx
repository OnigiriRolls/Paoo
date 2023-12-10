#include "GameState.hpp"

namespace Underworld
{
    GameState::GameState()
    {
        this->enemies = -1;
        this->players = -1;
    }

    GameState::GameState(int players, int enemies) : players(players), enemies(enemies) {}

    void GameState::setPlayers(const int players)
    {
        this->players = players;
    }

    int GameState::getPlayers() const
    {
        return players;
    }

    void GameState::setEnemies(const int enemies)
    {
        this->enemies = enemies;
    }

    int GameState::getEnemies() const
    {
        return enemies;
    }
}