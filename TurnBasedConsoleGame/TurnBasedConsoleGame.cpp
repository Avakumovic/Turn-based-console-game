// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include "Movement.h"

bool gameRunning = true;

int x = 1;
int y = 1;

char map[10][20] = {
	"###################",
	"#O                #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"#                 #",
	"###################",
};


int main()
{
	Movement movement;

	while (gameRunning = true) {

		system("cls");
		for (int display = 0; display < 10; display++) {
			std::cout << map[display] << std::endl;
		}
		movement.MovePlayer(map);

	}
	return 0;

}