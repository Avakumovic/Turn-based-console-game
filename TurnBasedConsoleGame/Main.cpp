// TurnBasedConsoleGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <Windows.h>
#include <memory>
#include <cstdlib>
#include <vector>
#include <stdlib.h>
#include "Movement.h"
#include "Player.h"
#include "Map.h"
#include "InventoryUI.h"
#include "Render.h"
#include <conio.h>


int main()
{	
	bool gameRunning = true;
	Movement movement;
	InventoryUI inventoryUI;	
	system("cls");
	Render::GetRender()->MapRender();
	int pressed_key;
	int second_press;
	bool canMove = false;
	while (gameRunning) {
		pressed_key = _getch();
		if (pressed_key == 224 || pressed_key == 0) { //ovo i canMove potrebno zbog nacina na koji _getch ucitava strelice u odnosu na ostale karaktere
			canMove = true;
			second_press = _getch();
		}
		if (inventoryUI.GetInventoryActive() == false && canMove == true) {
			movement.MovePlayer(second_press);
		}
		if ((Player::GetPlayer()->GetInventoryItems()).size() >= 1) {
			inventoryUI.OpenInventory(pressed_key);
		}
		if (pressed_key == 27) {
			exit(0);
		}
		canMove = false;
	}
	return 0;
}