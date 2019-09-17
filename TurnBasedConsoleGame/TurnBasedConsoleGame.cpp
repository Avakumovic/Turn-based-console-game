// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include <cstdlib>
#include <vector>
#include "Movement.h"
#include "Player.h"
#include "Map.h"


int main()
{	
	bool gameRunning = true;
	std::shared_ptr<Map> mapload(Map::GetMap());
	std::shared_ptr<std::vector<char>> map = mapload->GetMapInstance();
	Movement movement;
	std::shared_ptr<Player> player(Player::GetPlayer());
	std::shared_ptr<std::vector<Enemy>> enemyList = mapload->GetAllEnemies();

	system("cls");
	for (std::vector<char>::iterator i = (*map).begin(); i != (*map).end(); i++) {
		std::cout << *i;
	}		
	std::cout << "Player HP: " << player->GetHealth() << std::endl;

	while (gameRunning = true) {

		movement.MovePlayer(enemyList);
	}
	return 0;
}