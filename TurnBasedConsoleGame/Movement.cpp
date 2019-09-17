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
	std::shared_ptr<std::vector<char>> map = mapload->GetMapInstance();

	std::shared_ptr<Player> thePlayer(Player::GetPlayer());

	for (std::vector<char>::iterator i = (*map).begin(); i != (*map).end(); i++) {
		std::cout << *i;
	}
	std::cout << "Player HP: " << thePlayer->GetHealth() << std::endl;
}

void Movement::TickPrinter(Enemy& enemy)
{
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	std::cout << "You've been hit for " << enemy.GetDamage() << std::endl;
	std::cout << "You've hit an enemy for " << thePlayer->GetDamage() << " damage!" << std::endl;
	if (enemy.GetHealth() == 0) {
		std::cout << "Enemy killed!" << std::endl;
	}
	else {
		std::cout << "Enemy HP: " << enemy.GetHealth() << std::endl;
	}
	
	
}

void Movement::EnemyInteraction(int new_index, std::shared_ptr<std::vector<Enemy>> enemyList)
{
	std::shared_ptr<Map> mapload(Map::GetMap());
	for (unsigned int i = 0; i < enemyList->size(); i++) {
		auto text = (*enemyList)[i].GetIndex();
		if ((*enemyList)[i].GetIndex() == new_index) {
			HitsAchieved((*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				mapload->ChangeMap(new_index, ' ');
			}
			TickRender();
			TickPrinter((*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				enemyList->erase(enemyList->begin() + i);
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

void Movement::MovePlayer(std::shared_ptr<std::vector<Enemy>> enemyList)
{
	system("pause>nul");
	std::shared_ptr<Map> mapload(Map::GetMap());
	std::shared_ptr<std::vector<char>> map = mapload->GetMapInstance();
	if (GetAsyncKeyState(0x28)) {//down
		int temp_pos = _index + _lineSize;
		if ((*map)[temp_pos] == ' ') {
			mapload->ChangeMap(_index, ' ');
			_index += _lineSize;
			mapload->ChangeMap(_index, '@');
			TickRender();
		}
		else if ((*map)[temp_pos] == '&')
		{
			EnemyInteraction(temp_pos, enemyList);
		}
	}

	if (GetAsyncKeyState(0x26)) {//up
		int temp_pos = _index - _lineSize;
		if ((*map)[temp_pos] == ' ') {
			mapload->ChangeMap(_index, ' ');
			_index -= _lineSize;
			mapload->ChangeMap(_index, '@');
			TickRender();
		}
		else if ((*map)[temp_pos] == '&')
		{
			EnemyInteraction(temp_pos, enemyList);
		}
	}

	if (GetAsyncKeyState(0x27)) {//right
		int temp_pos = _index + 1;
		if ((*map)[temp_pos] == ' ') {
			mapload->ChangeMap(_index, ' ');
			_index += 1;
			mapload->ChangeMap(_index, '@');
			TickRender();
		}
		else if ((*map)[temp_pos] == '&')
		{
			EnemyInteraction(temp_pos, enemyList);
		}
	}

	if (GetAsyncKeyState(0x25)) {//left
		int temp_pos = _index - 1;
		if ((*map)[temp_pos] == ' ') {
			mapload->ChangeMap(_index, ' ');
			_index -= 1;
			mapload->ChangeMap(_index, '@');
			TickRender();
		}
		else if ((*map)[temp_pos] == '&')
		{
			EnemyInteraction(temp_pos, enemyList);
		}
	}
}
