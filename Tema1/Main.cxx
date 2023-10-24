#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Enemy.hpp"

int main(int argc, char const *argv[])
{
    char alice[] = "Alice";
    char ana[] = "Ana";
    char minion1[] = "Minion1";
    char minion2[] = "Minion2";
    char boss[] = "Boss";

    Character player = Player(alice);

    {
        Character copiedPlayer = player;
        player.setName(ana);
        Character enemyMinion1 = Enemy(minion1, 20);
        {
            Character enemyMinion2 = Enemy(minion2, 25);
            Character copyEnemyMinion1 = enemyMinion1;
        }
    }

    Character enemyBoss = Enemy(boss, 30);

    return 0;
}