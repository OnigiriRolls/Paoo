#pragma once
#include "Character.hpp"

class Enemy : public Character
{
public:
    Enemy(const char *name);
    Enemy(const Enemy &other);
    Enemy(Enemy &&other) noexcept;
    ~Enemy();
    Enemy &operator+(const Enemy &other);
    Enemy &operator=(const Enemy &other);
    Enemy &operator=(Enemy &&other) noexcept;
    Enemy(const char *name, int attack);
    void SetAttack(int attack);
    int GetAttack();

private:
    int attack;
};
