#pragma once
#include "Character.h"
class Player : public Character
{
private:
	static Player* instance;
	Player();
	Player(const Player&);
public:
	~Player();
	static Player* GetPlayer();
};

