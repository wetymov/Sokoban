#pragma once
#include "SokobanEngine.h"
#include "conio.h"
#include <chrono>
#include <thread>

class Game {
private:
	string StartMessage = "START GAME SOKOBAN by wetymov";
	string SelectLevels = "    �������� ������� :\n1 - test\n2 - easy level\n3 - info level ";
	int number_level;
	Level level;
	void select_level(int number) {
		Level level1(number);
		level = level1;
		cout << "������ ������� : " << number << endl;
	}

public:
	Game() {
		system("chcp 1251");
	}

	void menu() {
		cout << StartMessage << endl;
		cout << SelectLevels << endl;
		cout << "������� ����� ������ : ";
		int n;
		cin >> n;
		if (n < 1 || n > 3) {
			system("cls");
			cout << "�� ����� �� ������������ ������� � ������������� ����� ���������� 1 �������\n";
			select_level(1);
		}
		else {
			select_level(n);
		}
	}

	void start_game() {
		Sokoban Soko(level);
		char n;
		while (true) {
			Soko.print_Board();
			n = _getch();
			if (n == 'w' || n == '�') Soko.move_up();
			if (n == 's' || n == '�') Soko.move_down();
			if (n == 'd' || n == '�') Soko.move_right();
			if (n == 'a' || n == '�') Soko.move_left();
			if (n == 'r' || n == '�') Soko.restart();
			system("cls");
		}
	}
};