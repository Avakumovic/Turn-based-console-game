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
	static std::shared_ptr<Map> GetMap(char map[20][20]);
	static std::shared_ptr<Map> GetMap();
	Map(char map[20][20]);
	~Map();
	std::shared_ptr<std::vector<Enemy>> GetAllEnemies();
};