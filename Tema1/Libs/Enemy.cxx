#include "Enemy.hpp"

Enemy::Enemy(const char* name) : Character(name) {
    this->attack = 0;
    std::cout << "Enemy " << name << ": constructor was called" << std::endl;
}

Enemy::Enemy(const Enemy& other) : Character(other) {
    std::cout << "Enemy " << this->name << ": copy constructor was called" << std::endl;
    this->attack = other.attack;
}

Enemy::Enemy(Enemy&& other) noexcept : Character(other) {
    std::cout << "Enemy " << this->name << ": move constructor was called" << std::endl;
    this->attack = other.attack;

    other.attack = 0;
}

Enemy::~Enemy() {
    if (this->name != NULL)
        std::cout << "Enemy " << this->name << ": destructor was called" << std::endl;
    else std::cout << "Enemy name=NULL: destructor was called" << std::endl;
}

Enemy& Enemy::operator+(const Enemy& other) {
    std::cout << "Enemy operator + overload was called" << std::endl;
    Character::operator+(other);
    this->attack += other.attack;

    return *this;
}

Enemy& Enemy::operator=(const Enemy& other) {
    std::cout << "Enemy copy operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
        this->attack = other.attack;
    }
    return *this;
}

Enemy& Enemy::operator=(Enemy&& other) noexcept {
    std::cout << "Enemy move operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
        this->attack = other.attack;

        other.attack = 0;
    }
    return *this;
}

Enemy::Enemy(const char* name, int attack) : Enemy(name)
{
    this->attack = attack;
}

void Enemy::SetAttack(int attack)
{
    this->attack = attack;
}

int Enemy::GetAttack()
{
    return this->attack;
}
