#include "pch.h"
#include "Item.h"
#include <utility>
#include <fstream>

Item::Item(std::string name, int dmg, int hp, ItemType type)
{
	this->SetItemName(name);
	this->SetDmgBonus(dmg);
	this->SetHpBonus(hp);
	this->SetItemType(type);
}

Item::Item()
{
	GetItemList();
}

Item::~Item()
{
}

std::string Item::GetItemName() {
	return _item_name;
}
void Item::SetItemName(std::string itemName) {
	_item_name = itemName;
}
int Item::GetHpBonus() {
	return _hp_bonus;
}
void Item::SetHpBonus(int hpBonus) {
	_hp_bonus = hpBonus;
}
int Item::GetDmgBonus() {
	return _dmg_bonus;
}
void Item::SetDmgBonus(int dmgBonus) {
	_dmg_bonus = dmgBonus;
}

ItemType Item::GetItemType() {
	return _item_type;
}
void Item::SetItemType(ItemType itemType) {
	_item_type = itemType;
}

void Item::GetItemList()
{
	this->itemList.insert(std::make_pair(1, Item("Savage dagger (+15 Dmg)", 15, 0, ItemType::Weapon)));
	this->itemList.insert(std::make_pair(2, Item("Thunderfury (+25 Dmg)", 25, 0, ItemType::Weapon)));
	this->itemList.insert(std::make_pair(3, Item("Caparace armor (+130 HP)", 0, 130, ItemType::Armor)));
	this->itemList.insert(std::make_pair(4, Item("Champion's breastplate (+200 HP)", 0, 200, ItemType::Armor)));
	this->itemList.insert(std::make_pair(5, Item("Lesser healing potion (Heal 130)", 0, 130, ItemType::Potion)));
	this->itemList.insert(std::make_pair(6, Item("Greater healing potion (Heal 200)", 0, 200, ItemType::Potion)));
}

Item Item::GetItem(int randomNum)
{
	auto iter = itemList.find(randomNum);
	return iter->second;
}

void Item::SaveItem()
{
	
}

void Item::LoadItem()
{
	
}