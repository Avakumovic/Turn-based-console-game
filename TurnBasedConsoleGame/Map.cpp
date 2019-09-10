#include "pch.h"
#include "Map.h"

#include <iostream>
#include <memory>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

Map::Map(char map[][20])
{
	int counter = 0;
	std::ifstream in;
	in.open("Map.txt");
	for (int i = 0; i < 20; i++) {
		for (int j = 0; j < 20; j++) {
			in.get(map[i][j]);
			if (map[i][j] == '&') {
				Enemy newEnemy;
				newEnemy.setX_position(i);
				newEnemy.setY_position(j);
				objectList[counter] = newEnemy;
				counter++;
			}
		}
	}
	in.close();
}

Map::~Map()
{
}

Object * Map::getObjectList()
{
	return objectList;
}
