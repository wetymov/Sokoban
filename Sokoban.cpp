﻿#include "include/SokobanEngine.h"
#include <fstream>
#include <string>
#include "conio.h"

using namespace std;

int main()
{
	Level m(1);
	Sokoban Soko(m);
	char n;
	while (true) {
		Soko.print_Board();
		n = _getch();
		if (n == 'w') Soko.move_up();
		if (n == 's') Soko.move_down();
		if (n == 'd') Soko.move_right();
		if (n == 'a') Soko.move_left();
		system("cls");
	}
	return 0;
}
