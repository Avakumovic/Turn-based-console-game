#pragma once
#include <iostream>
#include "Object.h"

class Character : public Object
{
private:
	std::string _name;
	int16_t _health;
	int16_t _damage;
public:
	Character();
	~Character();

	std::string GetName();
	void SetName(std::string newName);
	int16_t GetHealth();
	void SetHealth(int16_t newHealth);
	void ChangeHealth(int16_t healthChange, char sign);
	int16_t GetDamage();
	void SetDamage(int16_t newDamage);
	void ChangeDamage(int16_t damageChange, char sign);
};