#pragma once

#include "Character.hpp"

class Player : public Character {
public:
    Player(const std::string& name);
    Player(const Player& other);
    ~Player();
};
