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

int Character::GetMaxHealth() {
	return _health;
}

void Character::SetMaxHealth(int newHealth) {
	_health = newHealth;
}

void Character::ChangeMaxHealth(int healthChange, char sign) {
	if (sign == '+') { //increase hp
		_maxHealth += healthChange;
	}
	else { //reduce hp
		_maxHealth -= healthChange;
		if (_maxHealth < 0)
			_maxHealth = 0;
	}
}

int Character::GetHealth() {
	return _health;
}

void Character::SetHealth(int newHealth) {
	_health = newHealth;
}

void Character::ChangeHealth(int healthChange, char sign) {
	if (sign == '+') { //increase hp
		_health += healthChange;
		if (_health > _maxHealth)
			_health = _maxHealth;
	}
	else { //reduce hp
		_health -= healthChange;
		if (_health < 0)
			_health = 0;
		//poginuo
	}
}

int Character::GetDamage() {
	return _damage;
}

void Character::SetDamage(int newDamage) {
	_damage = newDamage;
}

void Character::ChangeDamage(int damageChange, char sign) {
	if (sign == '+') { //increase dmg
		_damage += damageChange;
	}
	else { //reduce dmg
		_damage -= damageChange;
		if (_damage < 0)
			_damage = 0;
	}
}