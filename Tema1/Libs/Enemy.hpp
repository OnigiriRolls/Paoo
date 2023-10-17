#pragma once

#include "Player.hpp" 

class Enemy : public Character {
public:
    Enemy(const std::string& name, int attack);
    Enemy(const Enemy& other);
    ~Enemy();
    void setAttack(int attack);
    int getAttack() const;
    void attackPlayer(Player& player);

private:
    int attack;
};
