#pragma once

#include "Character.hpp"

class Player : public Character {
public:
    Player(char* name);
    Player(const Player& other);
    ~Player();
};
