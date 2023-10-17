#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Enemy.hpp"

int main(int argc, char const* argv[])
{
    Player player("Alice");
    Player copiedPlayer = player;

    player.setName("Ana");
    Enemy minion1("Minion1", 20);
    Enemy minion2("Minion", 25);
    Enemy boss("Boss", 30);

    return 0;
}