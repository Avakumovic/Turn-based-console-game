#pragma once
#include "Character.h"
class Enemy : public Character
{
private:

public:
	Enemy(std::string name, int16_t health, int16_t damage, int16_t x, int16_t y);
	Enemy();
	~Enemy();

};

