#include "Character.hpp"

Character::Character(char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
    this->hp = 100;
}

Character::~Character() {
    //printf("Destructor character");
    delete[] this->name;
}

Character::Character(const Character& other) {
    this->name = new char[strlen(other.name) + 1];
    strcpy(this->name, other.name);
    this->hp = other.hp;
}

void Character::setName(char* name) {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);
}

char* Character::getName() const {
    return name;
}

void Character::setHp(int hp) {
    this->hp = hp;
}

int Character::getHp() const {
    return hp;
}