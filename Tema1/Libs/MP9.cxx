#include "MP9.hpp"

MP9::MP9()
{
    std::cout << "MP9: constructor was called" << std::endl;
    this->noShots = 100;
    this->totalPower = 1000;
}

MP9::MP9(MP9&& other) noexcept
{
    std::cout << "MP9: move constructor was called" << std::endl;
    this->noShots = other.noShots;
    this->totalPower = other.totalPower;
}

void MP9::rapidFire() const
{
    std::cout << "Rapid fire is on!" << std::endl;
}

double MP9::calculateDamage(int playerHp) const
{
    if (playerHp < 50) {
        return (double) ((this->totalPower * 10) / this->noShots);
    }
    return (double) (this->totalPower / this->noShots);
}

void MP9::toString() const
{
    std::cout << "MP9 is a gun for close range" << std::endl;
}

void MP9::setNoShots(const int noShots)
{
    this->noShots = noShots;
}

int MP9::getNoShots() const
{
    return this->noShots;
}

void MP9::setTotalPower(const int totalPower)
{
    this->totalPower = totalPower;
}

int MP9::getTotalPower() const
{
    return this->totalPower;
}
