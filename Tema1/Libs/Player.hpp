#pragma once
#include "Character.hpp"
#include "Gun.hpp"
#include <memory>

namespace Arena
{
    class Player : public Character
    {
    public:
        Player();
        Player(const char *name);
        Player(const Player &other);
        Player(Player &&other) noexcept;
        ~Player();
        Player &operator+(const Player &other);
        Player &operator=(const Player &other);
        Player &operator=(Player &&other) noexcept;
        void toString() const override;
        void setGun(Gun *gun);
        void useGun() const;

    private:
        Gun *gun;
    };
}
