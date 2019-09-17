#include "pch.h"
#include "Enemy.h"

Enemy::Enemy(std::string name, int health, int damage, int index)
{
	this->SetName(name);
	this->SetHealth(health);
	this->SetDamage(damage);
	this->SetIndex(index);
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
