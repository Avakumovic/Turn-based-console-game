#include "pch.h"
#include "SaveLoad.h"
#include "Map.h"
#include "Render.h"

SaveLoad* SaveLoad::instance = NULL;

SaveLoad * SaveLoad::SaveLoadGame()
{
	if (instance == NULL) {
		instance = new SaveLoad();
	}
	return instance;
}

SaveLoad::SaveLoad()
{
}

void SaveLoad::SaveGame()
{
	Player::GetPlayer()->SavePlayer();
	Map::GetMap()->SaveMap();
	Render::GetRender()->MapRender();
	Render::GetRender()->GameSaved();
	Render::GetRender()->ClearLines();
}

void SaveLoad::LoadGame()
{
	Player::GetPlayer()->LoadPlayer();
	Map::GetMap()->LoadMap();
	Render::GetRender()->MapRender();
	Render::GetRender()->GameLoaded();
	Render::GetRender()->ClearLines();
}


SaveLoad::~SaveLoad()
{
}

