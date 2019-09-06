#pragma once
#include <iostream>
#include "Object.h"

class Character : public Object
{
private:
	std::string name;
	int16_t health;
	int16_t damage;
public:
	Character();
	~Character();

	std::string getName();
	void setName(std::string newName);
	int16_t getHealth();
	void setHealth(int16_t newHealth);
	void changeHealth(int16_t healthChange, bool sign);
	int16_t getDamage();
	void setDamage(int16_t newDamage);
	void changeDamage(int16_t damageChange, bool sign);
};