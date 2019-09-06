#include "pch.h"
#include "Character.h"


Character::Character()
{
}


Character::~Character()
{
}

std::string Character::getName() {
	return name;
}

void Character::setName(std::string newName) {
	name = newName;
}

int16_t Character::getHealth() {
	return health;
}

void Character::setHealth(int16_t newHealth) {
	health = newHealth;
}

void Character::changeHealth(int16_t healthChange, bool sign) {
	if (sign == true) { //add hp
		health += healthChange;
		if (health > 100)
			health = 100;
	}
	else { //reduce hp
		health -= healthChange;
		if (health < 0)
			health = 0;
		//poginuo
	}
}

int16_t Character::getDamage() {
	return damage;
}

void Character::setDamage(int16_t newDamage) {
	damage = newDamage;
}

void Character::changeDamage(int16_t damageChange, bool sign) {
	if (sign == true) { //add dmg
		damage += damageChange;
	}
	else { //reduce dmg
		damage -= damageChange;
		if (damage < 0)
			damage = 0;
	}
}