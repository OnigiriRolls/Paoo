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

void runGameThread(int id, const int numberPlayers)
{
    int i = 0;
    Player p;
    Gun *gun;
    Player *players = new Player[numberPlayers];

    if (players == NULL)
    {
        std::cerr << "Memory allocation failed." << std::endl;
        return;
    }

    for (i = 0; i < numberPlayers; i++)
    {
        char aux[3] = {'p', static_cast<char>(i + 49)};
        p = Player(aux);
        gun = new MP9();

        p.setGun(gun);
        players[i] = p;
    }

    Game *game = new Game(players, numberPlayers);
    bestPlayer = game->start();

    std::cout << bestPlayer->getName() << std::endl;
    std::cout << std::endl
              << "-- Final destructors --" << std::endl;
}

int main(int argc, char const *argv[])
{
    std::cout << std::endl
              << "-- Threads and semaphores --" << std::endl;

    runGameThread(1, 3);

    return 0;
}