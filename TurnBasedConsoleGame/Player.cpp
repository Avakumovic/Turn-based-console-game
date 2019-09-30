#include "pch.h"
#include "Player.h"
#include <iostream>
#include <fstream>

Player* Player::instance = NULL;

Player* Player::GetPlayer() {
	if (instance == NULL) {
		instance = new Player();
	}
	return instance;
}

Player::Player()
{
	this->SetName("Hero");
	this->SetHealth(200);
	this->SetDamage(20);
}

Player::~Player()
{
}

void Player::SetPosition(int position) {
	_position = position;
}

int Player::GetPosition() {
	return _position;
}


Item Player::GetEquipedWeapon() {
	return _equiped_weapon;
}

void Player::SetEquipedWeapon(Item weapon) {
	if (_no_weapon == false) {
		instance->ChangeDamage(_equiped_weapon.GetDmgBonus(), '-');
	}
	_equiped_weapon = weapon;
	instance->ChangeDamage(weapon.GetDmgBonus(), '+');
}

Item Player::GetEquipedArmor() {
	return _equiped_weapon;
}

void Player::SetEquipedArmor(Item armor) {
	if (_no_armor == false) {
		instance->ChangeMaxHealth(_equiped_armor.GetHpBonus(), '-');
	}
	_equiped_armor = armor;
	instance->ChangeMaxHealth(armor.GetHpBonus(), '+');	
}

void Player::UseItem(int index)
{
	switch (_inventory[index].GetItemType())
	{
	case Weapon:
		if (_inventory[index].GetItemName() != _equiped_weapon.GetItemName()) {
			if (_no_weapon == false) {
				instance->ChangeDamage(_equiped_weapon.GetDmgBonus(), '-');
			}
			_equiped_weapon = _inventory[index];
			_no_weapon = false;
			instance->ChangeDamage(_inventory[index].GetDmgBonus(), '+');
		}
		break;
	case Armor:
		if (_inventory[index].GetItemName() != _equiped_armor.GetItemName()) {
			if (_no_armor == false) {
				instance->ChangeMaxHealth(_equiped_armor.GetHpBonus(), '-');
				instance->ChangeHealth(_equiped_armor.GetHpBonus(), '-');
			}
			_equiped_armor = _inventory[index];
			_no_armor = false;
			instance->ChangeMaxHealth(_inventory[index].GetHpBonus(), '+');
			instance->ChangeHealth(_inventory[index].GetHpBonus(), '+');
		}
		break;
	case Potion:
		instance->ChangeHealth(_inventory[index].GetHpBonus(), '+');
		instance->RemoveItemFromInventory(index);
		break;
	default:
		break;
	}
}

void Player::AddItemToInventory(Item newItem)
{
	_inventory.emplace_back(newItem);
}

std::vector<Item> Player::GetInventoryItems()
{
	return _inventory;
}

void Player::SavePlayer()
{
	std::ofstream file{ "PlayerSaved.txt" };
	boost::archive::text_oarchive outputArchive{ file };
	outputArchive << *instance;
}

void Player::LoadPlayer()
{
	std::ifstream file{"PlayerSaved.txt"};
	boost::archive::text_iarchive inputArchive{file};
	inputArchive >> *instance;
}

void Player::RemoveItemFromInventory(int index)
{
	_inventory.erase(_inventory.begin() + index);
}