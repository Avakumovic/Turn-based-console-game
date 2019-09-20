#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iterator>

enum ItemType { Weapon, Armor, Potion };

class Item
{
private:
	std::string _item_name;
	int _hp_bonus;
	int _dmg_bonus;
	ItemType _item_type;
	std::map<int, Item> itemList;
public:
	Item(std::string, int, int, ItemType);
	Item();
	~Item();
	std::string GetItemName();
	void SetItemName(std::string itemName);
	int GetHpBonus();
	void SetHpBonus(int hpBonus);
	int GetDmgBonus();
	void SetDmgBonus(int dmgBonus);
	ItemType GetItemType();
	void SetItemType(ItemType itemType);
	void GetItemList();
	Item GetItem(int);
};

