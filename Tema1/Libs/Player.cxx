#include "Player.hpp"

Player::Player(const char* name) : Character(name) {
    std::cout << "Player " << name << ": constructor was called" << std::endl;
}

Player::Player(const Player& other) : Character(other) {
    std::cout << "Player " << this->name << ": copy constructor was called" << std::endl;
}

Player::Player(Player&& other) noexcept : Character(other) {
    std::cout << "Character " << this->name << ": move constructor was called" << std::endl;
}

Player::~Player() {
    if (this->name != NULL)
        std::cout << "Player " << this->name << ": destructor was called" << std::endl;
    else std::cout << "Player name=NULL: destructor was called" << std::endl;
}

Player& Player::operator+(const Player& other) {
    std::cout << "Player operator + overload was called" << std::endl;
    Character::operator+(other);
    return *this;
}

Player& Player::operator=(const Player& other) {
    std::cout << "Player copy operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
    }
    return *this;
}

Player& Player::operator=(Player&& other) noexcept {
    std::cout << "Player move operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
    }
    return *this;
}