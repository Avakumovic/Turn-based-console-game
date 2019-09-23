#include "pch.h"
#include "Map.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm> 

std::shared_ptr<Map> Map::instance = NULL;

std::shared_ptr<Map> Map::GetMap() {
	if (instance == NULL) {
		instance = std::make_shared<Map>(Map());
	}
	return (instance);
}

std::shared_ptr<std::vector<char>> Map::GetMapInstance()
{
	return std::make_shared<std::vector<char>>(mainMap);
}

Map::Map()
{
	int counter = 0;
	std::ifstream in;
	char input;
	in.open("Map.txt");
	while (in.get(input)) {
		mainMap.emplace_back(input);
		if (input == '&') {
			int randomHP = rand() % 150 + 50;
			int randomDmg = rand() % 20 + 10;
			Enemy newEnemy("Troll", randomHP, randomDmg, counter);
			allEnemies.emplace_back(newEnemy);
		}
		counter++;
	}
	in.close();
}

Map::~Map()
{
}

std::shared_ptr<std::vector<Enemy>> Map::GetAllEnemies()
{
	std::shared_ptr<std::vector<Enemy>> ptr_allEnemies = std::make_shared<std::vector<Enemy>>(instance->allEnemies);
	return ptr_allEnemies;
}

void Map::ChangeMap(int index, char element)
{
	mainMap[index] = element;
}
