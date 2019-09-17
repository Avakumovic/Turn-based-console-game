#pragma once
#include <iostream>
#include "Object.h"

class Character : public Object
{
private:
	std::string _name;
	int _maxHealth;
	int _health;
	int _damage;
public:
	Character();
	~Character();
	std::string GetName();
	void SetName(std::string newName);
	int GetMaxHealth();
	void SetMaxHealth(int newHealth);
	void ChangeMaxHealth(int healthChange, char sign);
	int GetHealth();
	void SetHealth(int newHealth);
	void ChangeHealth(int healthChange, char sign);
	int GetDamage();
	void SetDamage(int newDamage);
	void ChangeDamage(int damageChange, char sign);
};