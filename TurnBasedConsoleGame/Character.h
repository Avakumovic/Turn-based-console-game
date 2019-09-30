#pragma once
#include <iostream>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <boost/serialization/export.hpp>
#include <boost/serialization/vector.hpp>

class Character
{
private:
	friend class boost::serialization::access;
	std::string _name;
	int _maxHealth = 200;
	int _health;
	int _damage;
	int _index;
	template<typename Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & _name;
		ar & _maxHealth;
		ar & _health;
		ar & _damage;
		ar & _index;
	}
public:
	Character();
	~Character();
	void SetIndex(int index);
	int GetIndex();
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