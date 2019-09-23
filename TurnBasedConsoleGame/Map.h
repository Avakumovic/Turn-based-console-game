#pragma once
#include "Object.h"
#include "Enemy.h"
#include <iostream>
#include <vector>

class Map
{
private:
	static std::shared_ptr<Map> instance;
	std::vector<Enemy> allEnemies;
public:
	std::vector<char> mainMap;
	static std::shared_ptr<Map> GetMap();
	std::shared_ptr<std::vector<char>> GetMapInstance();
	Map();
	~Map();
	std::shared_ptr<std::vector<Enemy>> GetAllEnemies();
	void ChangeMap(int, char);
};