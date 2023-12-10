#include "Game.hpp"

namespace Arena
{
    Game::Game()
    {
        this->players = NULL;
        this->nr = 0;
    }

    Game::Game(const Player *players, int nr)
    {
        setPlayers(players, nr);
        this->nr = nr;
    }

    Player *Game::start()
    {
        if (this->nr != 0 && this->players != NULL)
        {
            srand(time(0));
            int bestPlayer = rand() % (this->nr - 1);
            std::cout << std::endl
                      << "Displaying last logs of game..." << std::endl;

            for (int i = 0; i < this->nr; i++)
            {
                if (i != bestPlayer)
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

    void Game::setPlayers(const Player *players, int nr)
    {
        delete[] this->players;
        this->players = new Player[nr];

        for (int i = 0; i < nr; i++)
        {
            this->players[i] = players[i];
        }
    }

    Player *Game::getPlayers() const
    {
        return this->players;
    }
}

namespace Underworld
{
    Game::Game()
    {
        this->gameState = NULL;
        this->gameStatistics = NULL;
        this->name = -1;
    }

    Game::Game(int name, std::shared_ptr<GameState> gameState) : name(name), gameState(gameState) {}

    Game::Game(int name, std::unique_ptr<GameStatistics> gameStatistics) : name(name), gameStatistics(std::move(gameStatistics)) {}

    void Game::start()
    {
        std::cout << "Underworld game " << this->name << " started!"
                  << " Current game state is:" << std::endl
                  << "Alive players: " << gameState->getPlayers() << std::endl
                  << "Alive enemies: " << gameState->getEnemies() << std::endl;

        std::this_thread::sleep_for(std::chrono::milliseconds(600));

        {
            std::lock_guard<std::mutex> lock(this->stateMutex);
            int currentPlayers = gameState->getPlayers();
            int currentEnemies = gameState->getEnemies();

            if (currentPlayers > 0)
            {
                currentPlayers--;
                gameState->setPlayers(currentPlayers);
            }
            else
            {
                std::cout << "All players died in game" << this->name << "! Game over!" << std::endl;
                return;
            }

            if (currentEnemies > 0)
            {
                currentEnemies--;
                gameState->setEnemies(currentEnemies);
            }
            else
            {
                std::cout << "All enemies died in game" << this->name << "! Game over!" << std::endl;
                return;
            }

            std::cout << "Underworld game " << this->name << " ended!"
                      << " Final game state is:" << std::endl
                      << "Alive players: " << gameState->getPlayers() << std::endl
                      << "Alive enemies: " << gameState->getEnemies() << std::endl;
        }
    }

    void Game::startWithGameStatistics()
    {
        std::cout << std::endl
                  << "Underworld game " << this->name << " with unique game statistics!" << std::endl
                  << "... game statistics are being completed ..." << std::endl;

        this->gameStatistics->setBloodDrinks(this->name);
        this->gameStatistics->setZombiesKilled(this->name);
        this->gameStatistics->setScore(this->name * 100 - this->name * 3);
    }

    void Game::getGameStatistics() const
    {
        std::cout << "Underworld game " << this->name << " has game statistics:" << std::endl;
        return this->gameStatistics->getStatistics();
    }
}
