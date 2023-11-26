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

using Underworld::Enemy;
using Arena::Player;
using Arena::AWP;
using Arena::MP9;
using Arena::Gun;
using Arena::Game;

Player bestPlayer;

int main(int argc, char const *argv[])
{
    std::cout << std::endl << "-- Threads and semaphores --" << std::endl;

    Player p1 = Player("p1");
    Player p2 = Player("p2");
    Player p3 = Player("p3");

    Gun* mp91 = new MP9();
    Gun* mp92 = new MP9();
    Gun* awp1 = new AWP();

    p1.setGun(mp91);
    p2.setGun(mp92);
    p3.setGun(awp1);
    Player players[3];

    players[0] = p1;
    players[1] = p2;
    players[2] = p3;

    Game game1(players, 3);

    game1.start();

    std::cout << std::endl << "-- Final destructors --" << std::endl;

    return 0;
}