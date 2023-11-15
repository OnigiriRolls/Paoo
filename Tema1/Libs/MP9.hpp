#pragma once
#include "Gun.hpp"

namespace Arena {
    class MP9 : public Gun
    {
    public:
        MP9();
        MP9(MP9&& other) noexcept;
        void rapidFire() const;
        double calculateDamage(int playerHp) const override;
        void toString() const override;
        MP9& operator=(MP9&& other) noexcept;
        void setNoShots(const int noShots);
        int getNoShots() const;
        void setTotalPower(const int totalPower);
        int getTotalPower() const;

    private:
        int noShots;
        int totalPower;
    };
}
