// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include <cstdlib>
#include <fstream>
#include <vector>
#include "Movement.h"
#include "Player.h"
#include "Map.h"


int main()
{	
	bool gameRunning = true;
	char map[20][20];

	Map mapload(map);
	Movement movement;
	std::shared_ptr<Player> player(Player::GetPlayer());
	std::shared_ptr<std::vector<Enemy>> enemyList = mapload.GetAllEnemies();

	system("cls");
		
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				std::cout << map[i][j];
			}
		}

	while (gameRunning = true) {

		std::cout << "Player HP: " << player->GetHealth() << std::endl;
		movement.MovePlayer(map, enemyList);

		system("cls");
		
		for (int i = 0; i < 20; i++) {
			for (int j = 0; j < 20; j++) {
				std::cout << map[i][j];
			}
		}
	}
	return 0;
}