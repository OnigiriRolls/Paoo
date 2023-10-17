#include "Enemy.hpp"

Enemy::Enemy(const std::string& name, int attack) : Character(name) {
    this->attack = attack;
}

Enemy::Enemy(const Enemy& other) : Character(other) {
    this->attack = other.attack;
}

Enemy::~Enemy(){}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

int Enemy::getAttack() const {
    return attack;
}

void Enemy::attackPlayer(Player& player) {
    printf("Enemy %s:Attacking player %s", this->getName(), player.getName());
    int playerHealth = player.getHp();
    playerHealth -= attack;
    player.setHp(playerHealth);
}