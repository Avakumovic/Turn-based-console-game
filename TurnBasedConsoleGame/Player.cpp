#include "pch.h"
#include "Player.h"

Player::Player(std::string name = "Hero", int16_t health = 200, int16_t damage = 40)
{
	this->SetName(name);
	this->SetHealth(health);
	this->GetDamage(damage);
}


Player::~Player()
{
}
