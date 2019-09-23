#pragma once
#include <iostream>

class Object
{
private:
	int _index;
public:
	Object();
	~Object();
	void SetIndex(int index);
	int GetIndex();
};

