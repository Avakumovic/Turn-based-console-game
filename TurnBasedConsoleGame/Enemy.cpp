#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, int16_t health, int16_t damage, int16_t x, int16_t y)
{
	this->SetName(name);
	this->SetHealth(health);
	this->GetDamage(damage);
	this->setX_position(x);
	this->setX_position(y);
}

Enemy::Enemy()
{
	this->SetName("Bot");
	this->SetHealth(100);
	this->GetDamage(15);
}

Enemy::~Enemy()
{
}
