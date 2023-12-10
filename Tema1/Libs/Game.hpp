#pragma once
#include "Player.hpp"
#include "GameState.hpp"
#include "GameStatistics.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>

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
        Game(int name, std::unique_ptr<GameStatistics> gameStatistics);
        void start();
        void startWithGameStatistics();
        void getGameStatistics() const;

    private:
        std::shared_ptr<GameState> gameState;
        int name;
        std::mutex stateMutex;
        std::unique_ptr<GameStatistics> gameStatistics;
    };
}
