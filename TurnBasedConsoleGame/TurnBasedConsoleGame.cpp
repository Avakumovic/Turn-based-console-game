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


bool gameRunning = true;

int x = 1;
int y = 1;

char map[20][20];


int main()
{	
	Map mapload(map);
	Object* mainObjectList = mapload.getObjectList();
	Movement movement;
	Player player("Noob", 300, 40);

	while (gameRunning = true) {

		system("cls");
		std::cout << *map << std::endl;
	
		std::cout << "Player HP: " << player.getHealth() << std::endl;
		movement.MovePlayer(map);


	}
	return 0;

}