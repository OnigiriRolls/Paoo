#pragma once

namespace Underworld
{
    class GameState
    {
    public:
        GameState();
        GameState(int players, int enemies);
        void setPlayers(const int newPlayers);
        int getPlayers() const;
        void setEnemies(const int newEnemies);
        int getEnemies() const;

    private:
        int players;
        int enemies;
    };
}