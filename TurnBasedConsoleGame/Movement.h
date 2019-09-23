#pragma once
#include <vector>
#include "Enemy.h"
class Movement
{
private:
	int _lineSize = 20;
public:
	Movement();
	~Movement();
	void MovePlayer(std::shared_ptr<std::vector<Enemy>>, int);
	void HitsAchieved(Enemy&);
	void EnemyInteraction(int, std::shared_ptr<std::vector<Enemy>>);
	void Move(int, std::shared_ptr<std::vector<Enemy>>);
};

