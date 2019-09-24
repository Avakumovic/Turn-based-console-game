#pragma once
#include "Object.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

class Map
{
private:
	static Map* instance;
	std::vector<Enemy> allEnemies;
	Map();
public:
	std::vector<char> mainMap;
	static Map* GetMap();
	std::vector<char>* GetMapInstance();
	~Map();
	std::vector<Enemy>* GetAllEnemies();
	void ChangeMap(int, char);
};