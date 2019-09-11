#include "pch.h"
#include "Movement.h"
#include <Windows.h>


Movement::Movement()
{

}


Movement::~Movement()
{
}

void Movement::MovePlayer(char map[20][20])
{
	system("pause>nul");
	if (GetAsyncKeyState(0x28)) {
		int y2 = _y + 1;
		if (map[y2][_x] == ' ') {
			map[_y][_x] = ' ';
			_y++;
			map[_y][_x] = '@';
		}
	}

	if (GetAsyncKeyState(0x26)) {
		int y2 = _y - 1;
		if (map[y2][_x] == ' ') {
			map[_y][_x] = ' ';
			_y--;
			map[_y][_x] = '@';
		}
	}

	if (GetAsyncKeyState(0x27)) {
		int x2 = _x + 1;
		if (map[_y][x2] == ' ') {
			map[_y][_x] = ' ';
			_x++;
			map[_y][_x] = '@';
		}
	}

	if (GetAsyncKeyState(0x25)) {
		int x2 = _x - 1;
		if (map[_y][x2] == ' ') {
			map[_y][_x] = ' ';
			_x--;
			map[_y][_x] = '@';
		}
	}
}
