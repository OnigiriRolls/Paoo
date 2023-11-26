#pragma once
#include "Player.hpp"
#include <vector>
#include <ctime>
#include <cstdlib>

namespace Arena {
    class Game
    {
    public:
        Game();
        Game(const Player* players, int nr);
        Player* start();
        ~Game();
        void setPlayers(const Player* players, int nr);
        Player* getPlayers() const;

    private:
        Player* players;
        int nr;
    };
}
