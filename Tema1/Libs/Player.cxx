#include "Player.hpp"

using namespace Arena;

std::mutex healthMutex;

Player::Player() : Character()
{
    this->gun = NULL;
}

Player::Player(const char *name) : Character(name)
{
    // std::cout << "Player " << name << ": constructor was called" << std::endl;
    this->gun = NULL;
}

Player::Player(const Player &other) : Character(other)
{
    // std::cout << "Player " << this->name << ": copy constructor was called" << std::endl;
    setGun(other.gun);
}

Player::Player(Player &&other) noexcept : Character(other)
{
    // std::cout << "Player " << this->name << ": move constructor was called" << std::endl;
    setGun(other.gun);
    other.gun = NULL;
}

Player::~Player()
{
    // if (this->name != NULL)
    // std::cout << "Player " << this->name << ": destructor was called" << std::endl;
    // else
    // std::cout << "Player name=NULL: destructor was called" << std::endl;

    this->gun = NULL;
}

Player &Player::operator+(const Player &other)
{
    // std::cout << "Player operator + overload was called" << std::endl;
    Character::operator+(other);
    return *this;
}

Player &Player::operator=(const Player &other)
{
    // std::cout << "Player copy operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
        setGun(other.gun);
    }
    return *this;
}

Player &Player::operator=(Player &&other) noexcept
{
    // std::cout << "Player move operator = overload was called" << std::endl;
    if (this != &other)
    {
        Character::operator=(other);
        setGun(other.gun);
        other.gun = NULL;
    }
    return *this;
}

void Player::toString() const
{
    std::cout << "I am a Player with name = " << this->name << " and hp = " << this->hp << std::endl;
}

void Player::setGun(Gun *gun)
{
    this->gun = gun;
}

void Player::useGun() const
{
    std::cout << "Player used gun with description: ";
    this->gun->toString();
    std::cout << "with damage: " << this->gun->calculateDamage(this->hp) << std::endl;
}

void Arena::Player::attack(Player &otherPlayer)
{
    int otherPlayerHealth = otherPlayer.getHp();
    double gunDamage = this->gun->calculateDamage(otherPlayerHealth);
    std::cout << "Player " << this->name << ", with gun damage:" << gunDamage << ", attacked player " << otherPlayer.getName() << std::endl;
    otherPlayer.loseHealth(gunDamage);
}

void Arena::Player::loseHealth(int damage)
{
    std::lock_guard<std::mutex> lock(healthMutex);

    if (this->hp - damage > 0)
    {
        std::cout << "Player " << this->name << ": old health = " << this->hp
                  << " and current health = " << this->hp - damage << std::endl;
        this->hp -= damage;
    }
    else
    {
        std::cout << "Player " << this->name << ": health <= 0! Player died!" << std::endl;
    }
}
