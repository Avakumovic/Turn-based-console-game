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
	void MovePlayer(int);
	void HitsAchieved(Enemy&);
	void EnemyInteraction(int);
	void Move(int);
};

