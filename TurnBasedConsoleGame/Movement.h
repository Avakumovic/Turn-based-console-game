#pragma once
#include <vector>
#include "Enemy.h"
class Movement
{
private:
	int _x = 1;
	int _y = 1;
	int _index = 21; //pocetna pozicija playera
	int _lineSize = 20;
public:
	Movement();
	~Movement();
	void MovePlayer(std::shared_ptr<std::vector<Enemy>>, int);
	void HitsAchieved(Enemy&);
	void EnemyInteraction(int, std::shared_ptr<std::vector<Enemy>>);
	void Move(int, std::shared_ptr<std::vector<Enemy>>);
};

