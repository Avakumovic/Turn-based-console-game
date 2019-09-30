#pragma once
#include <iostream>
#include <map>
#include <string>
#include <iterator>
#include <sstream>
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>

enum ItemType { Weapon, Armor, Potion };

class Item
{
private:
	friend class boost::serialization::access;
	std::string _item_name;
	int _hp_bonus;
	int _dmg_bonus;
	ItemType _item_type;
	std::map<int, Item> itemList;
	template<typename Archive>
	void serialize(Archive & ar, const unsigned int version)
	{
		ar & _item_name;
		ar & _hp_bonus;
		ar & _dmg_bonus;
		ar & _item_type;
	}
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
	void SaveItem();
	void LoadItem();
};