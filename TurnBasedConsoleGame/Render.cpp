#include "pch.h"
#include "Render.h"
#include "Player.h"
#include <string>

std::shared_ptr<Render> Render::instance = NULL;

std::shared_ptr<Render> Render::GetRender()
{
	if (instance == NULL) {
		instance = std::make_shared<Render>(Render());
	}
	return (instance);
}

Render::Render()
{
}

Render::~Render()
{
}

void Render::MapRender()
{
	printf("\033[%d;%dH", 1, 1);
	std::vector<char>* map = Map::GetMap()->GetMapInstance();

	for (std::vector<char>::iterator i = (*map).begin(); i != (*map).end(); i++) {
		std::cout << *i;
	}
	std::cout << "Player HP: " << Player::GetPlayer()->GetHealth() << "      " << std::endl;
}

void Render::EnemyFightRender(Enemy* enemy)
{
	std::cout << "You've been hit for " << enemy->GetDamage() << "                                                                " << std::endl;
	std::cout << "You've hit an enemy for " << Player::GetPlayer()->GetDamage() << " damage!" << std::endl;
	if (enemy->GetHealth() == 0) {
		std::cout << "Enemy killed!" << std::endl;
	}
	else {
		std::cout << "Enemy HP: " << enemy->GetHealth() << "      " << std::endl;
	}
}

void Render::ItemPrintRender(Item& item)
{
	switch (item.GetItemType())
	{
	case Weapon:
		std::cout << "You have equiped a weapon: " << item.GetItemName() << std::endl;
		break;
	case Armor:
		std::cout << "You have equiped an armor: " << item.GetItemName() << std::endl;
		break;
	case Potion:
		std::cout << "You have used " << item.GetItemName() << std::endl;
		break;
	default:
		break;
	}
}

void Render::NewItemPrint(std::string itemName)
{
	std::cout << "You have pick up new item: " << itemName << std::endl << "\33[2K\r" << std::endl << "\33[2K\r" << std::endl;
}

void Render::ClearLines()
{
	std::cout << "\33[2K\r" << std::endl << "\33[2K\r" << std::endl << "\33[2K\r" << std::endl << "\33[2K\r" << std::endl;
}

void Render::GameSaved()
{
	std::cout << "Game saved!" << "                                                 " << std::endl;
}

void Render::GameLoaded()
{
	std::cout << "Game loaded!" << "                                                 " << std::endl;
}


