#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Convert_txt_to_level.h"

using namespace std;

class Sokoban {
private:
	vector<vector<string>> level;
	int level_size;
public:
	Sokoban(Level get_l) { // в конструктор получаем уровень
		level = get_l.get_level();
		level_size = level.size();
	}





	void print_Board() {
		for (int i = 0; i < level.size(); i++) {
			for (int j = 0; j <= level.size(); j++) {
				cout << level[i][j];
			}
			cout << "\n";
		}
	}
	/*

(y,x) декартова система координат
(y,x) = (i,j)


	*/
	void move_up() {
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == "@") {
					y = i;
					x = j;
					break;
				}
			}
		}
		if (level[y - 1][x] != "#" && level[y - 1][x] != "O") swap(level[y][x],level[y-1][x]);
		else if (level[y - 1][x] == "O") {
			if (level[y - 2][x] != "O" && level[y - 1][x] != "#") {
				swap(level[y][x],level[y - 2][x]);
				swap(level[y - 1][x], level[y - 2][x]);
			}
		}
	}

	void move_down() {
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == "@") {
					y = i;
					x = j;
					break;
				}
			}
		}
		if (level[y + 1][x] != "#" && level[y + 1][x] != "O") swap(level[y][x], level[y + 1][x]);
		else if (level[y + 1][x] == "O") {
			if (level[y + 2][x] != "O" && level[y + 1][x] != "#") {
				swap(level[y][x], level[y + 2][x]);
				swap(level[y + 1][x], level[y + 2][x]);
			}
		}
	}

	void move_left() {
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == "@") {
					y = i;
					x = j;
					break;
				}
			}
		}
		if (level[y][x-1] != "#" && level[y][x-1] != "O") swap(level[y][x-1], level[y][x]);
		else if (level[y][x-1] == "O") {
			if (level[y][x-2] != "O" && level[y][x-2] != "#") {
				swap(level[y][x], level[y][x-2]);
				swap(level[y][x-1], level[y][x-2]);
			}
		}
	}

	void move_right() {
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == "@") {
					y = i;
					x = j;
					break;
				}
			}
		}
		if (level[y][x + 1] != "#" && level[y][x + 1] != "O") swap(level[y][x + 1], level[y][x]);
		else if (level[y][x + 1] == "O") {
			if (level[y][x + 2] != "O" && level[y][x + 2] != "#") {
				swap(level[y][x], level[y][x + 2]);
				swap(level[y][x + 1], level[y][x + 2]);
			}
		}
	}
};
