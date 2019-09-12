#pragma once

#include <iostream>
#include <vector>
#include "Object.h"
#include "Enemy.h"

class Map
{
private:
	static Map* instance;
	Map(const Map&);
	std::vector<Enemy> allObjects;
public:
	static Map* GetMap();
	Map(char map[20][20]);
	~Map();
	std::vector<Enemy>* GetAllObjects();
};