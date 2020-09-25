#pragma once
#include <Windows.h>
#include "Objeto.h"

class Nave : public Objeto {
private:
	string figura2;
public:
	Nave();
	void mostrar();
	void borrar();
	void mover(char direc);
};

Nave::Nave() {
	this->figura2 = string(1, 221) + string(4, 220) + string(1, 222);
	this->figura = string(2, 220);
	this->dx = 5;
	this->dy = 5;
	this->x = Console::WindowWidth / 2;
	this->y = Console::WindowHeight - 3;
}

void Nave::mover(char direc) {
	if (direc == 75) {
		if (x - dx  - 3>= 0) {
			x -= dx;
		}
	}
	if (direc == 77){
		if (x + dx  + 3<= Console::WindowWidth) {
			x += dx;
		}
	}
}

void Nave::mostrar() {
	Console::ForegroundColor = ConsoleColor::Blue;
	gotoxy(x, y);
	cout << figura;
	Console::ForegroundColor = ConsoleColor::DarkYellow;
	gotoxy(x - 2, y + 1);
	cout << figura2;
}

void Nave::borrar() {
	gotoxy(x, y);
	cout << "   ";
	gotoxy(x - 2, y + 1);
	cout << "      ";
}          