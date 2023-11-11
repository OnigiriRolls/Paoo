#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Player.hpp"
#include "Libs/Enemy.hpp"

int main(int argc, char const *argv[])
{
    Enemy e1 = Enemy("en1");
    Enemy e2 = Enemy("en2", 100);

    Player p1 = Player("p1");
    Player p2 = Player("p2");

    Character c1 = Player("c1");
    Character c2 = Player("c2");

    e1 + e2;
    p1 + p2;
    c1 + c2;

    return 0;
}