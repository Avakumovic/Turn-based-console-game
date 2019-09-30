#include "pch.h"
#include "Map.h"
#include "Enemy.h"
#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <iterator>
#include <sstream>
#include <algorithm> 

Map* Map::instance = NULL;

Map* Map::GetMap() {
	if (instance == NULL) {
		instance = new Map();
	}
	return instance;
}

std::vector<char>* Map::GetMapInstance()
{
	return &mainMap;
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

std::vector<Enemy>* Map::GetAllEnemies()
{
	return &allEnemies;
}

void Map::ChangeMap(int index, char element)
{
	mainMap[index] = element;
}

void Map::SaveMap()
{
	std::ofstream file{ "MapSaved.txt" };
	boost::archive::text_oarchive outputArchive{ file };
	outputArchive << *instance;
}

void Map::LoadMap()
{
	std::ifstream file{ "MapSaved.txt" };
	boost::archive::text_iarchive inputArchive{ file };
	inputArchive >> *instance;
}
