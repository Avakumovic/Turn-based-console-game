#include "pch.h"
#include "Object.h"


Object::Object()
{
}


Object::~Object()
{
}

void Object::SetIndex(int index)
{
	this->_index = index;
}

int Object::GetIndex()
{
	return _index;
}
