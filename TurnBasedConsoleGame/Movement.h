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
	void MovePlayer(std::shared_ptr<char[][20]>, std::shared_ptr<std::vector<Enemy>>);
	void HitsAchieved(Enemy&);
	void TickRender();
	void TickPrinter(Enemy&);
	void EnemyInteraction(char*, std::shared_ptr<std::vector<Enemy>>, int*, bool);
};

