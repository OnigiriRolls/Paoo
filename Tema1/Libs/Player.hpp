#pragma once
#include "Character.hpp"

class Player : public Character {
public:
    Player(const char* name);
    Player(const Player& other);
    Player(Player&& other) noexcept;
    ~Player();
    Player& operator+(const Player& other);
};
