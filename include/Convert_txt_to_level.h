﻿/*
@ - игрок
# - стена
x - метка на которую необходимо поместить блок
O - блок
0 - блок стоящий на метке
*/

#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Level {
private:
	vector<vector<string>> level_1() { // first level sokoban :)
		vector<vector<string>> l{
			{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," ","X"," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," ","O"," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," ","X","O"," "," ","@"," "," ","O","X"," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," ","O"," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," ","X"," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#"," "," "," "," "," "," "," "," "," "," "," "," "," "," "," ","#",},
			{"#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#","#",},
		};
		return l;
	}
public:
	vector<vector<string>> level;
	Level(int number_level) { // конструктор для default уровней
		if (number_level == 1) {
			level = level_1();
		}
	}
	Level(string path) { // конструктор для кастомный уровней
		ifstream fin;
		fin.open(path, ios_base::in);
		if (fin.is_open()) {

		}
		fin.close();
	}
	vector<vector<string>> get_level() { // получаем наш уровень
		return level;
	}
};