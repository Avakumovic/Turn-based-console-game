#pragma once

#include <iostream>
#include <vector>
#include "Object.h"
#include "Enemy.h"

class Map
{
private:
	static std::shared_ptr<Map> instance;
	std::vector<Enemy> allEnemies;
public:
	char mainMap[20][20];
	static std::shared_ptr<Map> GetMap();
	std::shared_ptr<char[][20]> GetMapInstance();
	Map();
	~Map();
	std::shared_ptr<std::vector<Enemy>> GetAllEnemies();
};