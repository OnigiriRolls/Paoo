#include "Enemy.hpp"

Enemy::Enemy(char* name, int attack) : Character(name) {
    this->attack = attack;
}

Enemy::Enemy(const Enemy& other) : Character(other) {
    this->attack = other.attack;
}

Enemy::~Enemy(){
    //std::cout<<"Destructor enemy";
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

int Enemy::getAttack() const {
    return attack;
}

void Enemy::attackPlayer(Player& player) {
    //std::cout << "Enemy " << this->getName() << ": Attacking player " << player.getName();
    int playerHealth = player.getHp();
    playerHealth -= attack;
    player.setHp(playerHealth);
}