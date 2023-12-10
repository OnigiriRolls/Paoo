#pragma once
#include "Player.hpp"
#include "GameState.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>

namespace Arena
{
    class Game
    {
    public:
        Game();
        Game(const Player *players, int nr);
        Player *start();
        ~Game();
        void setPlayers(const Player *players, int nr);
        Player *getPlayers() const;

    private:
        Player *players;
        int nr;
    };
}

namespace Underworld
{
    class Game
    {
    public:
        Game();
        Game(int name, std::shared_ptr<GameState> gameState);
        void start();
        void end();

    private:
        std::shared_ptr<GameState> gameState;
        int name;
        std::mutex stateMutex;
    };
}
