#pragma once
#include "Enemy.h"
#include <iostream>
#include <vector>

class Map
{
private:
	friend class boost::serialization::access;
	static Map* instance;
	std::vector<Enemy> allEnemies;
	std::vector<char> mainMap;
	Map();
	template <typename Archive>
	void serialize(Archive &ar, const unsigned int version) {
		ar & allEnemies;
		ar & mainMap;
	};
public:
	static Map* GetMap();
	std::vector<char>* GetMapInstance();
	~Map();
	std::vector<Enemy>* GetAllEnemies();
	void ChangeMap(int, char);
	void SaveMap();
	void LoadMap();
};