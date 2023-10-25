#pragma once
#include "Character.hpp"

class Enemy : public Character
{
public:
    Enemy(const char* name);
    Enemy(const Enemy& other);
    Enemy(Enemy&& other) noexcept;
    ~Enemy();
    Enemy(const char* name, int attack);
    void SetAttack(int attack);
    int GetAttack();

private:
    int attack;
};

