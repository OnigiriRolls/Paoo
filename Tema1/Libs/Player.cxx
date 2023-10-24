#include "Player.hpp"

Player::Player(char* name) : Character(name) {
}

Player::Player(const Player& other) : Character(other) {
}

Player::~Player() {
    //std::cout<<"Destructor player";
}