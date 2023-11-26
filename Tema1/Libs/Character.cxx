#include "Character.hpp"

Character::Character()
{
    this->name = NULL;
    this->hp = 100;
}

Character::Character(const char* name) {
    std::cout << "Character " << name << ": constructor was called" << std::endl;

    this->name = NULL;
    setName(name);
    this->hp = 100;
}

Character::Character(const Character& other) {
    std::cout << "Character " << other.name << ": copy constructor was called" << std::endl;

    setName(other.name);
    this->hp = other.hp;
}

Character::Character(Character&& other) noexcept {
    std::cout << "Character " << other.name << ": move constructor was called" << std::endl;

    delete[] this->name;
    this->name = other.name;
    this->hp = other.hp;
    other.name = NULL;
    other.hp = 0;
}

Character::~Character() {
    if (this->name != NULL)
        std::cout << "Character " << this->name << ": destructor was called" << std::endl;
    else std::cout << "Character name=NULL: destructor was called" << std::endl;

    delete[] this->name;
}

Character& Character::operator+(const Character& other) {
    std::cout << "Character operator + overload was called" << std::endl;
    this->hp += other.hp;
    return *this;
}

Character& Character::operator=(const Character& other) {
    std::cout << "Character copy operator = overload was called" << std::endl;
    if (this != &other)
    {
        setName(other.name);
        this->hp = other.hp;
    }
    return *this;
}

Character& Character::operator=(Character&& other) noexcept {
    std::cout << "Character move operator + overload was called" << std::endl;
    if (this != &other)
    {
        delete[] this->name;
        this->name = other.name;
        this->hp = other.hp;

        other.name = NULL;
        other.hp = 0;
    }
    return *this;
}

void Character::toString() const {
    std::cout << "I am a Character with name = " << this->name << " and hp = " << this->hp << std::endl;
}

void Character::setName(const char* name) {
    delete[] this->name;
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char* Character::getName() const {
    return this->name;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getHp() const {
    return this->hp;
}