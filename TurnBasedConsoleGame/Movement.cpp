#include "pch.h"
#include "Movement.h"
#include "Map.h"
#include "Player.h"
#include "Enemy.h"
#include <Windows.h>
#include <vector>


Movement::Movement()
{

}


Movement::~Movement()
{
}

void Movement::HitsAchieved(Enemy enemy)
{
	Player* thePlayer = Player::GetPlayer();
	thePlayer->ChangeHealth(enemy.GetDamage(), '-');
	enemy.ChangeHealth(thePlayer->GetDamage(), '-');
}

void Movement::MovePlayer(char map[20][20], std::vector<Enemy>* enemyList)
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
