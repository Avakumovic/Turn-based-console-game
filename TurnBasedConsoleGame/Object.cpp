#include "pch.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::setX_position(int16_t newX)
{
	this->x_position = newX;
}

int16_t Object::getX_position()
{
	return x_position;
}

void Object::setY_position(int16_t newY)
{
	this->y_position = newY;
}

int16_t Object::getY_position()
{
	return y_position;
}
