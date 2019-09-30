#pragma once
#include "Character.h"
#include "Item.h"
#include <vector>
#include <memory>

class Player : public Character
{
private:
	static Player* instance;
	Item _equiped_weapon;
	Item _equiped_armor;
	bool _no_weapon = true;
	bool _no_armor = true;
	int _position = 21;
	std::vector<Item> _inventory;
	friend class boost::serialization::access;
	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version) { // parametar version sluzi za version control
		ar & _equiped_weapon;
		ar & _equiped_armor;
		ar & _no_weapon;
		ar & _no_armor;
		ar & _position;
		ar & _inventory;
		ar & boost::serialization::base_object<Character, Player>(*this);
	};
public:
	Player();
	~Player();
	static Player* GetPlayer();
	int GetPosition();
	void SetPosition(int);
	Item GetEquipedWeapon();
	void SetEquipedWeapon(Item);
	Item GetEquipedArmor();
	void SetEquipedArmor(Item);
	void UseItem(int);
	void RemoveItemFromInventory(int);
	void AddItemToInventory(Item);
	std::vector<Item> GetInventoryItems();
	void SavePlayer();
	void LoadPlayer();
};