#pragma once

#include <iostream>
#include "Object.h"
#include "Enemy.h"

class Map
{
private:
	Object objectList[];
public:
	Map(char map[][20]);
	~Map();
	Object* getObjectList();
};