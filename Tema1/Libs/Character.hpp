#pragma once
#include <cstring>

class Character
{
public:
    Character(char* name);
    ~Character();
    Character(const Character& other);
    void setName(char* name);
    char* getName() const;
    void setHp(int hp);
    int getHp() const;

private:
    char* name;
    int hp;
};