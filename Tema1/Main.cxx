#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Enemy.hpp"

int main(int argc, char const *argv[])
{
    Character player = Player("Alice");

    {
        Character copiedPlayer = player;
        player.setName("Ana");
        Character enemyMinion1 = Enemy("Minion1", 20);
        {
            Character enemyMinion2 = Enemy("Minion2", 25);
            Character copyEnemyMinion1 = enemyMinion1;
        }
    }

    Character enemyBoss = Enemy("Boss", 30);

    return 0;
}