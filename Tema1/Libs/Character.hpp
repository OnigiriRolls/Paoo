#pragma once
#include <cstring>
#include <iostream>

class Character
{
public:
    Character();
    Character(const char *name);
    Character(const Character &other);
    Character(Character &&other) noexcept;
    ~Character();
    Character &operator+(const Character &other);
    Character &operator=(const Character &other);
    Character &operator=(Character &&other) noexcept;
    virtual void toString() const;
    void setName(const char *name);
    char *getName() const;
    void setHp(int hp);
    int getHp() const;

protected:
    char *name;
    int hp;
};