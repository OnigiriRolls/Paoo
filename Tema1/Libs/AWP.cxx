#include "AWP.hpp"

AWP::AWP()
{
    std::cout << "AWP: constructor was called" << std::endl;
}

AWP::AWP(AWP&& other) noexcept
{
    std::cout << "AWP: move constructor was called" << std::endl;
}

void AWP::putScope() const
{
    std::cout << "Scope is on!" << std::endl;
}

double AWP::calculateDamage(int playerHp) const
{
    if (playerHp < 10) {
        return 2000.0;
    }
    return 1000.0;
}

void AWP::toString() const
{
    std::cout << "AWP is a gun for long range" << std::endl;
}

AWP& AWP::operator=(AWP&& other) noexcept
{
    std::cout << "AWP move operator = overload was called" << std::endl;
    return *this;
}
