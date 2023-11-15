#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Player.hpp"
#include "Libs/Enemy.hpp"
#include "Libs/AWP.hpp"
#include "Libs/MP9.hpp"
#include "Libs/GameStatistics.hpp"

using Underworld::Enemy;
using Arena::Player;
using Arena::AWP;
using Arena::MP9;

int main(int argc, char const *argv[])
{
    Enemy e1 = Enemy("e1");
    Enemy e2 = Enemy("e2", 100);

    Player p1 = Player("p1");
    Player p2 = Player("p2");

    Character c1 = Player("c1");
    Character c2 = Enemy("c2");

    std::cout << std::endl
              << "-- Operator + overload --" << std::endl;
    e1 + e2;
    p1 + p2;
    c1 + c2;

    std::cout << std::endl
              << "-- Copy operator = --" << std::endl;
    e1 = e2;
    p1 = p2;
    c1 = e1;
    c2 = p1;

    std::cout << std::endl
              << "-- Move operator = --" << std::endl;
    c1 = std::move(e2);

    std::cout << std::endl
              << "-- Virtual function --" << std::endl;

    Character *c4 = &p1;
    Character *c5 = &e1;
    Character *c6 = &c1;
    c4->toString();
    c5->toString();
    c6->toString();

    std::cout << std::endl
              << "-- Interface Gun --" << std::endl;
    Player p3 = Player("p3");
    Player p4 = Player("p4");

    p3.setHp(9);
    p4.setHp(80);

    AWP awp = AWP();
    MP9 mp9 = MP9();

    p3.setGun(&awp);
    p4.setGun(&mp9);

    p3.useGun();
    p4.useGun();

    std::cout << std::endl
              << "-- Namespaces: Arena and Underworld --" << std::endl;

    Arena::GameStatistics game1 = Arena::GameStatistics(10, 5);
    Underworld::GameStatistics game2 = Underworld::GameStatistics(5, 2);

    std::cout << "Arena Game" << std::endl;
    game1.getStatistics();
    std::cout << "Underworld Game" << std::endl;
    game2.getStatistics();

    std::cout << std::endl
              << "-- Final destructors --" << std::endl;

    return 0;
}