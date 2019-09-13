#include "pch.h"
#include "Player.h"

std::shared_ptr<Player> Player::instance = NULL;

std::shared_ptr<Player> Player::GetPlayer() {
	if (instance == NULL) {
		instance = std::make_shared<Player>(Player());
	}
	return (instance);
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
