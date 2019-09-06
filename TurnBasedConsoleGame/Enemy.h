#pragma once
#include "Character.h"
class Enemy :
	public Character
{
private:
	int16_t id;
public:
	Enemy(std::string name, int16_t health, int16_t damage);
	~Enemy();

	void setId(int16_t newId);
	int16_t getId();
};

