#pragma once
class Movement
{
private:
	int x = 1;
	int y = 1;

public:
	Movement();
	~Movement();
	void MovePlayer(char map[20][20]);
};

