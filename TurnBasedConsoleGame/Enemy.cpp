#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, int16_t health, int16_t damage, int16_t x, int16_t y)
{
	this->setName(name);
	this->setHealth(health);
	this->setDamage(damage);
	this->setX_position(x);
	this->setX_position(y);
}


Enemy::Enemy()
{
	this->setName("Bot");
	this->setHealth(100);
	this->setDamage(15);
}

Enemy::~Enemy()
{
}
