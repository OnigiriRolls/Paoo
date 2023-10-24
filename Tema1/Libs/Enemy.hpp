#pragma once

#include "Player.hpp" 
#include <iostream>
#include "Character.hpp"

class Enemy : public Character {
public:
    Enemy(char* name, int attack);
    Enemy(const Enemy& other);
    ~Enemy();
    void setAttack(int attack);
    int getAttack() const;
    void attackPlayer(Player& player);

private:
    int attack;
};
