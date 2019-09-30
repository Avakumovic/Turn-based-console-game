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

//skloni ovaj parametar
void Movement::MovePlayer(int pressed_key)
{
	int temp_pos;
	switch (pressed_key)
	{
	case 80: //down
		temp_pos = Player::GetPlayer()->GetPosition() +_lineSize;
		Move(temp_pos);
		break;
	case 72: //up
		temp_pos = Player::GetPlayer()->GetPosition() - _lineSize;
		Move(temp_pos);
		break;
	case 77: //right
		temp_pos = Player::GetPlayer()->GetPosition() + 1;
		Move(temp_pos);
		break;
	case 75: //left
		temp_pos = Player::GetPlayer()->GetPosition() - 1;
		Move(temp_pos);
		break;
	default:
		break;
	}
}

void Movement::Move(int targetPos)
{
	std::shared_ptr<Render> render(Render::GetRender());
	Map* mapload(Map::GetMap());
	Player* thePlayer = Player::GetPlayer();
	switch ((*(mapload->GetMapInstance()))[targetPos])
	{
	case ' ':
		mapload->ChangeMap(thePlayer->GetPosition(), ' ');
		thePlayer->SetPosition(targetPos);
		mapload->ChangeMap(thePlayer->GetPosition(), '@');
		render->MapRender();
		render->ClearLines();
		break;
	case '&':
		EnemyInteraction(targetPos);
		break;
	case 'i':
		srand((unsigned int)time(0));
		Item init;
		Item newItem = init.GetItem(rand() % 6 + 1);
		mapload->ChangeMap(thePlayer->GetPosition(), ' ');
		thePlayer->SetPosition(targetPos);
		mapload->ChangeMap(thePlayer->GetPosition(), '@');
		thePlayer->AddItemToInventory(newItem);
		render->MapRender();
		render->NewItemPrint(newItem.GetItemName());
		break;
	}
}

void Movement::HitsAchieved(Enemy& enemy)
{
	Player::GetPlayer()->ChangeHealth(enemy.GetDamage(), '-');
	enemy.ChangeHealth(Player::GetPlayer()->GetDamage(), '-');
}

void Movement::EnemyInteraction(int new_index)
{
	std::shared_ptr<Render> render(Render::GetRender());
	std::vector<Enemy>* enemyList = Map::GetMap()->GetAllEnemies();
	for (unsigned int i = 0; i < enemyList->size(); i++) {
		if ((*enemyList)[i].GetIndex() == new_index) {
			HitsAchieved((*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				(Map::GetMap())->ChangeMap(new_index, 'i');
			}
			render->MapRender();
			render->EnemyFightRender(&(*enemyList)[i]);
			if (((*enemyList)[i]).GetHealth() == 0) {
				enemyList->erase(enemyList->begin() + i);
			}
			if ((Player::GetPlayer())->GetHealth() <= 0) {
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

