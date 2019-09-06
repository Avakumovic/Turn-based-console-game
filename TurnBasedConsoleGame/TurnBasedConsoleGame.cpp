// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include "Movement.h"
#include "Player.h"

bool gameRunning = true;

int x = 1;
int y = 1;

char map[20][20] = {
	"###################",
	"#@   #      #     #",
	"#    #      #  &  #",
	"#    #      #     #",
	"#    #####     ####",
	"#        #        #",
	"#    #   #####    #",
	"######   #        #",
	"#        #        #",
	"#   ######        #",
	"#     ##    ##### #",
	"#   & ##          #",
	"#   #### #####    #",
	"#     #      #    #",
	"#    ##   #  #    #",
	"#         #  #    #",
	"#         #  #    #",
	"#         #      &#",
	"###################",
};


int main()
{
	Movement movement;
	Player player("Noob", 300, 40);

	while (gameRunning = true) {

		system("cls");
		for (int display = 0; display < 20; display++) {
			std::cout << map[display] << std::endl;
		}
		std::cout << "Player HP: " << player.getHealth() << std::endl;
		movement.MovePlayer(map);

	}
	return 0;

}