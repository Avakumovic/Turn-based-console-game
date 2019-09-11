// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include <cstdlib>
#include <fstream>
#include "Movement.h"
#include "Player.h"
#include "Map.h"





int main()
{	
	bool gameRunning = true;
	char map[20][20];


	Map mapload(map);
	Movement movement;
	Player player("Noob", 200, 40);

	while (gameRunning = true) {

		system("cls");
		std::cout << *map << std::endl;
	
		std::cout << "Player HP: " << player.GetHealth() << std::endl;
		movement.MovePlayer(map);

	}
	return 0;

}