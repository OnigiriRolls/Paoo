#include "Player.hpp"

Player::Player(const std::string& name) : Character(name) {
}

Player::Player(const Player& other) : Character(other) {
}

Player::~Player() {
}