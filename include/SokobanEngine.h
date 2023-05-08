#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "Convert_txt_to_level.h"

#define player "@" // игрок
#define player_in_point "!" // игрок находящийся на ячейке для ящика
#define barrier "#" // барьер
#define box "O" // коробка\ящик
#define point "X" // ячейка для ящика
#define box_in_point "0" // ящик стоящий на ячейке

using namespace std;

class Sokoban {
private:
	vector<vector<string>> level;
	vector<vector<string>> clear_level;
	int level_size;
	string flag = "@";
public:
	Sokoban(Level get_l) { // в конструктор получаем уровень
		level = get_l.get_level();
		level_size = level.size();
		clear_level = level;
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
	void move_up() { // перемещение вверх с помощью замены координат y в отрицательную сторону
		
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == player || level[i][j] == player_in_point) {
					y = i;
					x = j;
					flag = level[i][j];
					break;
				}
			}
		}
		if (level[y - 1][x] != barrier && level[y - 1][x] != box && level[y - 1][x] != point) swap(level[y][x],level[y-1][x]);
		else if (level[y - 1][x] == box) {
			if (level[y - 2][x] == point) {
				level[y][x] = " ";
				level[y - 1][x] = player;
				level[y - 2][x] = box_in_point;
			}
			else if (level[y - 2][x] != box && level[y - 2][x] != barrier) {
				swap(level[y][x],level[y - 2][x]);
				swap(level[y - 1][x], level[y - 2][x]);
			}
		}
	}

	void move_down() { // перемещение вниз с помощью замены координат y в положительную сторону
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == player || level[i][j] == player_in_point) {
					y = i;
					x = j;
					flag = level[i][j];
					break;
				}
			}
		}
		if (level[y + 1][x] != barrier && level[y + 1][x] != box && level[y + 1][x] != point) swap(level[y][x], level[y + 1][x]);
		else if (level[y + 1][x] == box) {
			if (level[y + 2][x] == point) {
				level[y][x] = " ";
				level[y + 1][x] = player;
				level[y + 2][x] = box_in_point;
			}
			else if (level[y + 2][x] != box && level[y + 2][x] != barrier) {
				swap(level[y][x], level[y + 2][x]);
				swap(level[y + 1][x], level[y + 2][x]);
			}
		}
	}

	void move_left() { // перемещение влево с помощью замены координат x в отрицательную сторону
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == player || level[i][j] == player_in_point) {
					y = i;
					x = j;
					flag = level[i][j];
					break;
				}
			}
		}
		if (level[y][x-1] != barrier && level[y][x-1] != box && level[y][x - 1] != point) swap(level[y][x - 1], level[y][x]);
		else if (level[y][x-1] == box) {
			if (level[y][x - 2] == point) {
				level[y][x] = " ";
				level[y][x - 1] = player;
				level[y][x - 2] = box_in_point;
			}
			else if (level[y][x - 2] != box && level[y][x - 2] != barrier) {
				swap(level[y][x], level[y][x - 2]);
				swap(level[y][x - 1], level[y][x - 2]);
			}
		}
	}

	void move_right() { // перемещение влево с помощью замены координат x в положительную сторону
		int x;
		int y;
		for (int i = 0; i < level_size; i++) {
			for (int j = 0; j <= level_size; j++) {
				if (level[i][j] == player || level[i][j] == player_in_point) {
					y = i;
					x = j;
					flag = level[i][j];
					break;
				}
			}
		}
		if (level[y][x + 1] != barrier && level[y][x + 1] != box && level[y][x + 1] != point) swap(level[y][x + 1], level[y][x]);
		else if (level[y][x + 1] == box) {
			if (level[y][x + 2] == point) {
				level[y][x] = " ";
				level[y][x + 1] = player;
				level[y][x + 2] = box_in_point;
			}
			else if (level[y][x + 1] == box_in_point) {

			}
			else if (level[y][x + 2] != box && level[y][x + 2] != barrier) {
				swap(level[y][x], level[y][x + 2]);
				swap(level[y][x + 1], level[y][x + 2]);
			}
		}
	}

	void restart() {
		level = clear_level;
		flag = "@";
	}
};
