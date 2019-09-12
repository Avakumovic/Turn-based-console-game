#include "pch.h"
#include "Player.h"

Player* Player::instance = NULL;

Player* Player::GetPlayer() {
	if (instance == NULL) {
		instance = new Player();
	}
	return(instance);
}

Player::Player()
{
	this->SetName("Hero");
	this->SetHealth(300);
	this->SetDamage(40);
}

Player::~Player()
{
}
