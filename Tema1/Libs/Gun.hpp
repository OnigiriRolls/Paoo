#pragma once
#include <iostream>
#include <string.h>

class Gun
{
public:
    virtual double calculateDamage(int playerHp) const = 0;
    virtual void toString() const = 0;
    virtual ~Gun() = default;
};