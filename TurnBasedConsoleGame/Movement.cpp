#include "pch.h"
#include "Movement.h"
#include "Map.h"
#include "Player.h"
#include "Render.h"
#include <ctime>
#include <Windows.h>
#include <vector>
#include <memory>
#include <string>

Movement::Movement()
{
}


Movement::~Movement()
{
}

void Movement::MovePlayer(std::shared_ptr<std::vector<Enemy>> enemyList, int pressed_key)
{
	std::shared_ptr<Render> render(Render::GetRender());
	std::shared_ptr<Map> mapload(Map::GetMap());
	std::shared_ptr<std::vector<char>> map = mapload->GetMapInstance();
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	std::shared_ptr<std::vector<Enemy>> enemyList1 = mapload->GetAllEnemies();
	int temp_pos;
	switch (pressed_key)
	{
	case 80: //down
		temp_pos = _index + _lineSize;
		Move(temp_pos, enemyList);
		break;
	case 72: //up
		temp_pos = _index - _lineSize;
		Move(temp_pos, enemyList);
		break;
	case 77: //right
		temp_pos = _index + 1;
		Move(temp_pos, enemyList);
		break;
	case 75: //left
		temp_pos = _index - 1;
		Move(temp_pos, enemyList);
		break;
	default:
		break;
	}
}

void Movement::Move(int targetPos, std::shared_ptr<std::vector<Enemy>> enemyList)
{
	std::shared_ptr<Render> render(Render::GetRender());
	std::shared_ptr<Map> mapload(Map::GetMap());
	std::shared_ptr<std::vector<char>> map = mapload->GetMapInstance();
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	switch ((*map)[targetPos])
	{
	case ' ':
		mapload->ChangeMap(_index, ' ');
		_index = targetPos;
		mapload->ChangeMap(_index, '@');
		render->MapRender();
		render->ClearLines();
		break;
	case '&':
		EnemyInteraction(targetPos, enemyList);
		break;
	case 'i':
		srand((unsigned int)time(0));
		Item init;
		Item newItem = init.GetItem(rand() % 6 + 1);
		mapload->ChangeMap(_index, ' ');
		_index = targetPos;;
		mapload->ChangeMap(_index, '@');
		thePlayer->AddItemToInventory(newItem);
		render->MapRender();
		render->NewItemPrint(newItem.GetItemName());
		break;
	}
}

void Movement::HitsAchieved(Enemy& enemy)
{
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	thePlayer->ChangeHealth(enemy.GetDamage(), '-');
	enemy.ChangeHealth(thePlayer->GetDamage(), '-');
}

void Movement::EnemyInteraction(int new_index, std::shared_ptr<std::vector<Enemy>> enemyList)
{
	std::shared_ptr<Render> render(Render::GetRender());
	std::shared_ptr<Map> mapload(Map::GetMap());
	std::shared_ptr<Player> thePlayer(Player::GetPlayer());
	for (unsigned int i = 0; i < enemyList->size(); i++) {
		auto text = (*enemyList)[i].GetIndex();
		if ((*enemyList)[i].GetIndex() == new_index) {
			HitsAchieved((*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				mapload->ChangeMap(new_index, 'i');
			}
			render->MapRender();
			render->EnemyFightRender((*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				enemyList->erase(enemyList->begin() + i);
			}
			if (thePlayer->GetHealth() <= 0) {
				std::cout << ">>>>>>>>>>>> YOU HAVE DIED <<<<<<<<<<<<<" << std::endl;
				exit(0);
			}
			if (enemyList->size() < 1) {
				std::cout << ">>>>>>>>>>>> YOU WIN! <<<<<<<<<<<<<" << std::endl;
				exit(0);
			}
		}
	}
}

