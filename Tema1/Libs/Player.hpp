#pragma once
#include "Character.hpp"
#include "Gun.hpp"
#include <memory>

class Player : public Character
{
public:
    Player(const char *name);
    Player(const Player &other);
    Player(Player &&other) noexcept;
    ~Player();
    Player &operator+(const Player &other);
    Player &operator=(const Player &other);
    Player &operator=(Player &&other) noexcept;
    void toString() const override;
    void setGun(std::unique_ptr<Gun> gun);
    void useGun() const;

private:
    std::unique_ptr<Gun> gun;
};
