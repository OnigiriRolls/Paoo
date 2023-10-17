#include "Character.hpp"

Character::Character(const std::string& name) {
    this->name = name;
    this->hp = 100;
}

Character::~Character() {
 
}

Character::Character(const Character& other) {
    this->name = other.name;
    this->hp = other.hp;
}

void Character::setName(const std::string& name) {
    this->name = name;
}

std::string Character::getName() const {
    return name;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getHp() const {
    return hp;
}
