#include "pch.h"
#include "Movement.h"
#include "Map.h"
#include "Player.h"
#include <Windows.h>
#include <vector>
#include <memory>


Movement::Movement()
{

}


Movement::~Movement()
{
}


void Movement::TickRender()
{
	system("cls");

	std::shared_ptr<Map> mapload(Map::GetMap());
	//auto map = mapload->GetMapInstance();
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			//std::cout << map[i][j];
		}
	}
	std::cout << "Player HP: " << thePlayer->GetHealth() << std::endl;


}

void Movement::TickPrinter(Enemy& enemy)
{
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	std::cout << "You've been hit for " << enemy.GetDamage() << std::endl;
	std::cout << "You've hit an enemy for " << thePlayer->GetDamage() << " damage!" << std::endl;
	std::cout << "Enemy HP: " << thePlayer->GetDamage() << " damage!" << std::endl;
	
}

void Movement::EnemyInteraction(char * new_pos, std::shared_ptr<std::vector<Enemy>> enemyList, int * temp_pos, bool axis)
{
	if (axis == true) {
		for (unsigned int i = 0; i < enemyList->size(); i++) {
			if (((*enemyList)[i].GetX_position() == *temp_pos) && ((*enemyList)[i].GetY_position() == _x)) {
				HitsAchieved((*enemyList)[i]);
				if (((*enemyList)[i]).GetHealth() == 0) {
					enemyList->erase(enemyList->begin() + i);
					*new_pos = ' ';	
				}
				//TickRender();
				TickPrinter((*enemyList)[i]);
			}
		}
	}
	else {
		for (unsigned int i = 0; i < enemyList->size(); i++) {
			if (((*enemyList)[i].GetX_position() == _y) && ((*enemyList)[i].GetY_position() == *temp_pos)) {
				HitsAchieved((*enemyList)[i]);
				if (((*enemyList)[i]).GetHealth() == 0) {
					enemyList->erase(enemyList->begin() + i);
					*new_pos = ' ';
				}
				//TickRender();
				TickPrinter((*enemyList)[i]);
			}
		}
	}	
}

void Movement::HitsAchieved(Enemy& enemy)
{
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	thePlayer->ChangeHealth(enemy.GetDamage(), '-');
	enemy.ChangeHealth(thePlayer->GetDamage(), '-');

}

void Movement::MovePlayer(std::shared_ptr<char[][20]> map, std::shared_ptr<std::vector<Enemy>> enemyList)
{
	system("pause>nul");
	if (GetAsyncKeyState(0x28)) {//down
		int temp_pos = _y + 1;
		if (map[temp_pos][_x] == ' ') {
			map[_y][_x] = ' ';
			_y++;
			map[_y][_x] = '@';
			TickRender();
		}
		else if (map[temp_pos][_x] == '&')
		{
			EnemyInteraction(&(map[temp_pos][_x]), enemyList, &temp_pos, true);
		}
	}

	if (GetAsyncKeyState(0x26)) {//up
		int temp_pos = _y - 1;
		if (map[temp_pos][_x] == ' ') {
			map[_y][_x] = ' ';
			_y--;
			map[_y][_x] = '@';
			TickRender();
		}
		else if (map[temp_pos][_x] == '&')
		{
			EnemyInteraction(&(map[temp_pos][_x]), enemyList, &temp_pos, true);
		}
	}

	if (GetAsyncKeyState(0x27)) {//right
		int temp_pos = _x + 1;
		if (map[_y][temp_pos] == ' ') {
			map[_y][_x] = ' ';
			_x++;
			map[_y][_x] = '@';
			TickRender();
		}
		else if (map[_y][temp_pos] == '&')
		{
			EnemyInteraction(&(map[temp_pos][_x]), enemyList, &temp_pos, false);
		}
	}

	if (GetAsyncKeyState(0x25)) {//left
		int temp_pos = _x - 1;
		if (map[_y][temp_pos] == ' ') {
			map[_y][_x] = ' ';
			_x--;
			map[_y][_x] = '@';
			TickRender();
		}
		else if (map[_y][temp_pos] == '&')
		{
			EnemyInteraction(&(map[temp_pos][_x]), enemyList, &temp_pos, false);
		}
	}
}
