#pragma once
#include "Character.h"
class Player :
	public Character
{
private:

public:
	Player(std::string name, int16_t health, int16_t damage);
	~Player();
};

