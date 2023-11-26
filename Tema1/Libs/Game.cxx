#include "Game.hpp"

namespace Arena {
    Game::Game()
    {
        this->players = NULL;
        this->nr = 0;
    }

    Game::Game(const Player* players, int nr)
    {
        setPlayers(players, nr);
        this->nr = nr;
    }

    Player* Game::start()
    {
        if (this->nr != 0 && this->players != NULL)
        {
            srand(time(0));
            int bestPlayer = rand() % (this->nr - 1);
            std::cout << std::endl << "Displaying last logs of game..." << std::endl;

            for (int i = 0; i < this->nr; i++) {
                if(i != bestPlayer)
                    std::cout << "Player " << this->players[bestPlayer].getName() << " killed Player " 
                    << this->players[i].getName() << std::endl;
            }

            return &(this->players[bestPlayer]);
        }

        std::cout << "Initialise game before starting!" << std::endl;
        return nullptr;
    }

    Game::~Game()
    {
        delete[] this->players;
    }

    void Game::setPlayers(const Player* players, int nr)
    {
        delete[] this->players;
        this->players = new Player[nr];

        for (int i = 0; i < nr; i++) {
            this->players[i] = players[i];
        }
    }

    Player* Game::getPlayers() const
    {
        return this->players;
    }
}
