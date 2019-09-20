#pragma once
#include "Character.h"
#include "Item.h"
#include <vector>
#include <memory>

class Player : public Character
{
private:
	static std::shared_ptr<Player> instance;
	Item _equiped_weapon;
	Item _equiped_armor;
	bool _no_weapon = true;
	bool _no_armor = true;
	std::vector<Item> _inventory;
public:
	Player();
	~Player();
	static std::shared_ptr<Player> GetPlayer();
	Item GetEquipedWeapon();
	void SetEquipedWeapon(Item);
	Item GetEquipedArmor();
	void SetEquipedArmor(Item);
	void UseItem(int);
	void RemoveItemFromInventory(int);
	void AddItemToInventory(Item);
	std::vector<Item> GetInventoryItems();
};