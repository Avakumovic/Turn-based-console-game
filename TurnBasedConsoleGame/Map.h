#pragma once

#include <iostream>
#include <vector>
#include "Object.h"
#include "Enemy.h"

class Map
{
private:

public:
	std::vector<Object> allObjects;
	Map(char map[][20]);
	~Map();
};