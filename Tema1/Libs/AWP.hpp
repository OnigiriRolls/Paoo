#pragma once
#include "Gun.hpp"

namespace Arena {
    class AWP : public Gun
    {
    public:
        AWP();
        AWP(AWP&& other) noexcept;
        void putScope() const;
        double calculateDamage(int playerHp) const override;
        void toString() const override;
        AWP& operator=(AWP&& other) noexcept;
    };
}
