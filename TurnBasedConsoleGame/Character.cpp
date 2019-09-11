#include "pch.h"
#include "Character.h"

Character::Character()
{
}

Character::~Character()
{
}

std::string Character::GetName() {
	return _name;
}

void Character::SetName(std::string newName) {
	_name = newName;
}

int16_t Character::GetHealth() {
	return _health;
}

void Character::SetHealth(int16_t newHealth) {
	_health = newHealth;
}

void Character::ChangeHealth(int16_t healthChange, bool sign) {
	if (sign == true) { //add hp
		_health += healthChange;
		if (_health > 100)
			_health = 100;
	}
	else { //reduce hp
		_health -= healthChange;
		if (_health < 0)
			_health = 0;
		//poginuo
	}
}

int16_t Character::GetDamage() {
	return _damage;
}

void Character::GetDamage(int16_t newDamage) {
	_damage = newDamage;
}

void Character::ChangeDamage(int16_t damageChange, bool sign) {
	if (sign == true) { //add dmg
		_damage += damageChange;
	}
	else { //reduce dmg
		_damage -= damageChange;
		if (_damage < 0)
			_damage = 0;
	}
}