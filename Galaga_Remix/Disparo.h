#pragma once
#include "Objeto.h"
enum tipo {amigo, enemigo};

class Disparo : public Objeto {
private:
	Direccion dir;
	tipo t_disparo;
public:
	Disparo(int, int, Direccion, tipo);
	void mostrar();
	void borrar();
	void mover();
	~Disparo();
};

Disparo::Disparo(int x, int y, Direccion dir, tipo dis) {
	t_disparo = dis;
	this->figura = "*";
	this->dy = 1;

	this->dir = dir;
	this->x = x;
	this->y = y;
}

void Disparo::mostrar() {
	if (t_disparo == amigo) Console::ForegroundColor = ConsoleColor::White;
	else  Console::ForegroundColor = ConsoleColor::Red;
	gotoxy(x, y);
	cout << figura;
}

void Disparo::borrar() {
	gotoxy(x, y);
	cout << " ";
}
void Disparo::mover() {
	switch (dir)
	{
	case Arriba:
		if (y - dy >= 0) {
			y -= dy;
		}
		break;
	case Abajo:
		if (y + dy <= Console::WindowHeight) {
			y += dy;
		}
		break;
	}
}

Disparo::~Disparo() {

}