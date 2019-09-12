#include "pch.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::SetX_position(int16_t newX)
{
	this->_x_position = newX;
}

int16_t Object::GetX_position()
{
	return _x_position;
}

void Object::SetY_position(int16_t newY)
{
	this->_y_position = newY;
}

int16_t Object::GetY_position()
{
	return _y_position;
}
