#include "pch.h"
#include "Movement.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <Windows.h>
#include <vector>
#include <memory>


Movement::Movement()
{

}


Movement::~Movement()
{
}

void Movement::HitsAchieved(Enemy& enemy)
{
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	thePlayer->ChangeHealth(enemy.GetDamage(), '-');
	enemy.ChangeHealth(thePlayer->GetDamage(), '-');
	
}

void Movement::TickRender(char map[20][20])
{
	
	system("cls");
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << map[i][j];
		}
	}

	//std::cout << "Player HP: " << thePlayer->GetHealth() << std::endl;
	//movement.MovePlayer(map, enemyList);

	system("cls");

	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			std::cout << map[i][j];
		}
	}
}

void Movement::TickPrinter()
{

}


void Movement::MovePlayer(char map[20][20], std::shared_ptr<std::vector<Enemy>> enemyList)
{

	system("pause>nul");
	if (GetAsyncKeyState(0x28)) {
		int y2 = _y + 1;
		if (map[y2][_x] == ' ') {
			map[_y][_x] = ' ';
			_y++;
			map[_y][_x] = '@';
		}
		else if (map[y2][_x] == '&')
		{
			for (unsigned int i = 0; i < enemyList->size(); i++) {
				if (((*enemyList)[i].GetX_position() == y2) && ((*enemyList)[i].GetY_position() == _x)) {
					HitsAchieved((*enemyList)[i]);
					if (((*enemyList)[i]).GetHealth() == 0) {
						enemyList->erase(enemyList->begin()+i);
						map[y2][_x] = ' ';
					}
				}
			}
		}
	}

	if (GetAsyncKeyState(0x26)) {
		int y2 = _y - 1;
		if (map[y2][_x] == ' ') {
			map[_y][_x] = ' ';
			_y--;
			map[_y][_x] = '@';
		}
	}

	if (GetAsyncKeyState(0x27)) {
		int x2 = _x + 1;
		if (map[_y][x2] == ' ') {
			map[_y][_x] = ' ';
			_x++;
			map[_y][_x] = '@';
		}
	}

	if (GetAsyncKeyState(0x25)) {
		int x2 = _x - 1;
		if (map[_y][x2] == ' ') {
			map[_y][_x] = ' ';
			_x--;
			map[_y][_x] = '@';
		}
	}


}
