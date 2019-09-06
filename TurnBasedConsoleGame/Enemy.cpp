#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name = "Bot", int16_t health = 100, int16_t damage = 15)
{
	this->setName(name);
	this->setHealth(health);
	this->setDamage(damage);
}

Enemy::~Enemy()
{
}

void Enemy::setId(int16_t newId) {
	this->id = newId;
}

int16_t Enemy::getId() {
	return id;
}