#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, int16_t health, int16_t damage, int16_t x, int16_t y)
{
	this->SetName(name);
	this->SetHealth(health);
	this->SetDamage(damage);
	this->SetX_position(x);
	this->SetX_position(y);
}

Enemy::Enemy()
{
	this->SetName("Troll");
	this->SetHealth(100);
	this->SetDamage(15);
}

Enemy::~Enemy()
{
}
