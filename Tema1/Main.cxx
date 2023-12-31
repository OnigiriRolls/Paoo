#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <thread>
#include <semaphore.h>

#include "Libs/Character.hpp"
#include "Libs/Game.hpp"
#include "Libs/Player.hpp"
#include "Libs/Enemy.hpp"
#include "Libs/AWP.hpp"
#include "Libs/MP9.hpp"
#include "Libs/Gun.hpp"
#include "Libs/GameStatistics.hpp"
#include "Libs/GameState.hpp"

using Arena::AWP;
using Arena::Game;
using Arena::Gun;
using Arena::MP9;
using Arena::Player;
using Underworld::Enemy;
using Underworld::GameState;

Player *bestPlayer;
double bestScore;
sem_t semaphore;
sem_t serverSemaphore;
std::shared_ptr<GameState> gameState;

void runGameThread(int id, const int numberPlayers)
{
    std::cout << std::endl
              << "Thread " << id << " is running a game..." << std::endl;
    int i = 0;
    Player p;
    Gun *gun;
    Player *players = new Player[numberPlayers];

    for (i = 0; i < numberPlayers; i++)
    {
        char aux[3] = {'p', static_cast<char>(i + 49)};
        p = Player(aux);
        gun = new MP9();

        p.setGun(gun);
        players[i] = p;
    }

    double score = (numberPlayers - 1) * 10;

    Game *game = new Game(players, numberPlayers);
    Player *localBest = game->start();

    sem_wait(&semaphore);
    if (score >= bestScore)
    {
        bestPlayer = localBest;
        bestScore = score;
    }

    std::cout << "Thread " << id << " finished and has a best local player and local score "
              << localBest->getName() << " " << score << std::endl
              << "Global best player and best score are: " << bestPlayer->getName() << " " << bestScore << std::endl;

    sem_post(&semaphore);
}

void simulateSamePlayerAttack(Player *player, Player *attacker)
{
    attacker->attack(*player);
}

void simulateSamePlayerAttackManager(const int numberPlayers)
{
    std::cout << "Simulation: -What if a player is attacked at the same time by others?- started..." << std::endl;

    int i = 0;
    Player p;
    Gun *gun;
    Player *players = new Player[numberPlayers];

    for (i = 0; i < numberPlayers; i++)
    {
        char aux[3] = {'p', static_cast<char>(i + 49)};
        p = Player(aux);
        gun = new MP9();

        p.setGun(gun);
        players[i] = p;
    }

    players[0].setHp(70);

    std::thread t1(simulateSamePlayerAttack, players, players + 1);
    std::thread t2(simulateSamePlayerAttack, players, players + 2);
    std::thread t3(simulateSamePlayerAttack, players, players + 3);
    std::thread t4(simulateSamePlayerAttack, players, players + 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Simulation ended..." << std::endl;
}

void requestServer(int index)
{
    sem_wait(&serverSemaphore);
    std::cout << "Player " << index << " is requesting server..." << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    sem_post(&serverSemaphore);
}

void simulateGameServerMaxPlayers()
{
    std::cout << "Small Game Server accepts requests from max 5 players" << std::endl
              << "What happens when there are 9 players?" << std::endl;

    sem_init(&serverSemaphore, 0, 5);

    std::thread threads[9];

    for (int i = 0; i < 9; ++i)
    {
        threads[i] = std::thread(requestServer, i + 1);
    }

    for (int i = 0; i < 9; ++i)
    {
        threads[i].join();
    }

    sem_destroy(&serverSemaphore);
}

void runThreads()
{
    sem_init(&semaphore, 0, 1);

    std::thread t1(runGameThread, 1, 3);
    std::thread t2(runGameThread, 2, 5);
    std::thread t3(runGameThread, 3, 5);
    std::thread t4(runGameThread, 4, 7);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    sem_destroy(&semaphore);
}

void startUnderworldGame(int name)
{
    Underworld::Game game(name, gameState);
    game.start();
}

void simulateSharedGameState()
{
    gameState = std::make_shared<GameState>();

    gameState->setEnemies(4);
    gameState->setPlayers(4);

    std::cout << "Simulate 4 game instances for 4 players with the same game state" << std::endl;

    std::thread t1(startUnderworldGame, 1);
    std::thread t2(startUnderworldGame, 2);
    std::thread t3(startUnderworldGame, 3);
    std::thread t4(startUnderworldGame, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

void startUnderworldGameWithStats(int name)
{
    std::unique_ptr<Underworld::GameStatistics> gameStatistics = std::make_unique<Underworld::GameStatistics>(0, 0);
    Underworld::Game game(name, std::move(gameStatistics));
    game.startWithGameStatistics();
    game.getGameStatistics();
}

void simulateGameWithUniqueGameStatistics()
{
    std::cout << std::endl
              << "Simulate 4 game instances for 4 players with unique game statistics for each one of them" << std::endl;

    std::thread t1(startUnderworldGameWithStats, 1);
    std::thread t2(startUnderworldGameWithStats, 2);
    std::thread t3(startUnderworldGameWithStats, 3);
    std::thread t4(startUnderworldGameWithStats, 4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();
}

int main(int argc, char const *argv[])
{
    std::cout << std::endl
              << "-- Threads and semaphores --" << std::endl;

    runThreads();
    std::cout << std::endl;
    simulateGameServerMaxPlayers();

    std::cout << std::endl
              << "-- RAI Mutex --" << std::endl;

    simulateSamePlayerAttackManager(5);

    std::cout << std::endl
              << "-- RAI Pointers --" << std::endl;

    simulateSharedGameState();
    simulateGameWithUniqueGameStatistics();
    return 0;
}