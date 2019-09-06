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
		int y2 = y + 1;
		if (map[y2][x] == ' ') {
			map[y][x] = ' ';
			y++;
			map[y][x] = '@';
		}
	}

	if (GetAsyncKeyState(0x26)) {
		int y2 = y - 1;
		if (map[y2][x] == ' ') {
			map[y][x] = ' ';
			y--;
			map[y][x] = '@';
		}
	}

	if (GetAsyncKeyState(0x27)) {
		int x2 = x + 1;
		if (map[y][x2] == ' ') {
			map[y][x] = ' ';
			x++;
			map[y][x] = '@';
		}
	}

	if (GetAsyncKeyState(0x25)) {
		int x2 = x - 1;
		if (map[y][x2] == ' ') {
			map[y][x] = ' ';
			x--;
			map[y][x] = '@';
		}
	}
}
