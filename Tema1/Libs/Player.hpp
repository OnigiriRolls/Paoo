#pragma once
#include "Character.hpp"
#include "Gun.hpp"
#include <memory>
#include <mutex>

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
        void attack(Player &otherPlayer);

    private:
        Gun *gun;
        void loseHealth(int damage);
    };
}
