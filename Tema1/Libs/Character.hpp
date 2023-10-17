#pragma once
#include <string>

class Character
{
public:
    Character(const std::string& name);
    ~Character();
    Character(const Character& other);
    void setName(const std::string& name);
    std::string getName() const;
    void setHp(int hp);
    int getHp() const;

private:
    std::string name;
    int hp;
};