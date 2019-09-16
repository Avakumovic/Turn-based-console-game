#include "pch.h"
#include "Map.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

std::shared_ptr<Map> Map::instance = NULL;

std::shared_ptr<Map> Map::GetMap() {
	if (instance == NULL) {
		instance = std::make_shared<Map>(Map());
	}
	return(instance);
}

std::shared_ptr<char[][20]> Map::GetMapInstance()
{
	return std::shared_ptr<char[][20]>(mainMap);
}

Map::Map()
{
	int counter = 0;
	std::ifstream in;
	in.open("Map.txt");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			in.get(mainMap[i][j]);
			if (mainMap[i][j] == '&') {
				Enemy newEnemy;
				newEnemy.SetX_position(i);
				newEnemy.SetY_position(j);
				allEnemies.emplace_back(newEnemy);
				counter++;
			}
		}
	}
	in.close();
}

Map::~Map()
{
}

std::shared_ptr<std::vector<Enemy>> Map::GetAllEnemies()
{
	std::shared_ptr<std::vector<Enemy>> ptr_allEnemies = std::make_shared<std::vector<Enemy>>(allEnemies);
	return ptr_allEnemies;
}
