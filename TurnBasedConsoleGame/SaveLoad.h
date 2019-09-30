#pragma once
#include <boost/archive/text_oarchive.hpp>
#include <boost/archive/text_iarchive.hpp>
#include <sstream>
#include "Player.h"

class SaveLoad
{
private:
	static SaveLoad* instance;
	SaveLoad();
public:
	static SaveLoad* SaveLoadGame();
	void SaveGame();
	void LoadGame();
	~SaveLoad();
};

