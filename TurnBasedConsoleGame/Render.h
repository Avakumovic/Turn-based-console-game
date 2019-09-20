#pragma once
#include "Map.h"
#include "Item.h"

class Render
{
private:
	static std::shared_ptr<Render> instance;
public:
	static std::shared_ptr<Render> GetRender();
	Render();
	~Render();
	void MapRender();
	void EnemyFightRender(Enemy&);
	void ItemPrintRender(Item&);
	void NewItemPrint(std::string);
	void ClearLines();
};

