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

using Arena::AWP;
using Arena::Game;
using Arena::Gun;
using Arena::MP9;
using Arena::Player;
using Underworld::Enemy;

Player *bestPlayer;
double bestScore;
sem_t semaphore;

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
    
    players[0].setHp(60);

    std::thread t1(simulateSamePlayerAttack, players, players+1);
    std::thread t2(simulateSamePlayerAttack, players, players+2);
    std::thread t3(simulateSamePlayerAttack, players, players+3);
    std::thread t4(simulateSamePlayerAttack, players, players+4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout << "Simulation ended..." << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << std::endl
              << "-- Threads and semaphores --" << std::endl;

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

    std::cout << std::endl
              << "-- RAI Mutex --" << std::endl;

    simulateSamePlayerAttackManager(5);

    return 0;
}