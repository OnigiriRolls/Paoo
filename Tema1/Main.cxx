#include <iostream>
#include <stdlib.h>
#include <stdio.h>

#include "Libs/Player.hpp"
#include "Libs/Enemy.hpp"

int main(int argc, char const *argv[])
{
     Character player(Player("Alice"));
    
    {
        Character copiedPlayer = player;
        player.setName("Ana");
        {
            Enemy enemy = Enemy("Minion", 25);
        }
    }
    
    player.setName("Cleo");
   

    return 0;
}