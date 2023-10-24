#pragma once
#include <iostream>
#include "Player.hpp" 
#include "Character.hpp"

class Enemy : public Character {
public:
    Enemy(const char* name, int attack);
    Enemy(const Enemy& other);
    Enemy(Enemy&& other) noexcept;
    ~Enemy();
    void setAttack(int attack);
    int getAttack() const;
    void attackPlayer(Player& player);

private:
    int attack;
};

