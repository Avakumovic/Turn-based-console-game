#pragma once
#include "Character.h"
#include <memory>

class Player : public Character
{
private:
	static std::shared_ptr<Player> instance;
public:
	Player();
	~Player();
	static std::shared_ptr<Player> GetPlayer();
};