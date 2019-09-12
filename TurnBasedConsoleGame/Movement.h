#pragma once
#include <vector>
#include "Enemy.h"
class Movement
{
private:
	int _x = 1;
	int _y = 1;

public:
	Movement();
	~Movement();
	void MovePlayer(char map[20][20], std::vector<Enemy>*);
	void HitsAchieved(Enemy enemy);
};

