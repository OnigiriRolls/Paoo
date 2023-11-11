#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Player.hpp"
#include "Libs/Enemy.hpp"

int main(int argc, char const *argv[])
{
    Enemy e1 = Enemy("e1");
    Enemy e2 = Enemy("e2", 100);

    Player p1 = Player("p1");
    Player p2 = Player("p2");

    Character c1 = Player("c1");
    Character c2 = Enemy("c2");

    std::cout << "-- Operator + overload --" << std::endl;
    e1 + e2;
    p1 + p2;
    c1 + c2;

    std::cout << "-- Copy operator = --" << std::endl;
    e1 = e2;
    p1 = p2;
    c1 = e1;
    c2 = p1;

    std::cout << "-- Move operator = --" << std::endl;
    c1 = std::move(e2);

    return 0;
}