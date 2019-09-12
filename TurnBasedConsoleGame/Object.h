#pragma once
#include <iostream>

class Object
{
private:
	int16_t _x_position;
	int16_t _y_position;
public:
	Object();
	~Object();
	void SetX_position(int16_t newX);
	int16_t GetX_position();
	void SetY_position(int16_t newY);
	int16_t GetY_position();
};

