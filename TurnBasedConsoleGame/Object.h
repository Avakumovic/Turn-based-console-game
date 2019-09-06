#pragma once
#include <iostream>

class Object
{
private:
	int16_t x_position;
	int16_t y_position;
public:
	Object();
	~Object();
	void setX_position(int16_t newX);
	int16_t getX_position();
	void setY_position(int16_t newY);
	int16_t getY_position();
};

