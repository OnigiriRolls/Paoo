#include "Enemy.hpp"

Enemy::Enemy(const char* name, int attack) : Character(name) {
    std::cout << "Enemy " << name << ": constructor was called" << std::endl;
    this->attack = attack;
}

Enemy::Enemy(const Enemy& other) : Character(other) {
    std::cout << "Enemy " << this->name << ": copy constructor was called" << std::endl;
    this->attack = other.attack;
}

Enemy::Enemy(Enemy&& other) noexcept : Character(other) {
    std::cout << "Character " << this->name << ": move constructor was called" << std::endl;
    this->attack = other.attack;
}

Enemy::~Enemy(){
    if (this->name != NULL)
        std::cout << "Enemy " << this->name << ": destructor was called" << std::endl;
    else std::cout << "Enemy name=NULL: destructor was called" << std::endl;
}

void Enemy::setAttack(int attack) {
    this->attack = attack;
}

int Enemy::getAttack() const {
    return attack;
}

void Enemy::attackPlayer(Player& player) {
    std::cout << "Enemy " << this->name << ": Attacking player " << player.getName() << std::endl;
    int playerHealth = player.getHp();
    playerHealth -= attack;
    player.setHp(playerHealth);
}