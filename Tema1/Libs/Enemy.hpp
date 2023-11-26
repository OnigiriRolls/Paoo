#pragma once
#include "Character.hpp"

namespace Underworld {
    class Enemy : public Character
    {
    public:
        Enemy();
        Enemy(const char* name);
        Enemy(const Enemy& other);
        Enemy(Enemy&& other) noexcept;
        ~Enemy();
        Enemy& operator+(const Enemy& other);
        Enemy& operator=(const Enemy& other);
        Enemy& operator=(Enemy&& other) noexcept;
        void toString() const override;
        Enemy(const char* name, int attack);
        void SetAttack(int attack);
        int GetAttack();

    private:
        int attack;
    };
}
