#pragma once
#include "Objeto.h"

enum tipoAvispa {Roja, Verde, Azul};

class Avispa : public Objeto {
private:
	int countdown_mov;
	tipoAvispa tipoavispa;
	int tipo_mov, limite_mov;
	int cooldownlado;
	bool dispararlaser, lado;

public:
	Avispa(int, int, int);
	void mover(Direccion);
	void mostrar();
	void borrar();
	bool getdispararlaser() {
		return dispararlaser;
	}
	void patronmovimiento();
};
Avispa::Avispa(int x, int y, int t) {
	this->limite_mov = 80;
	this->cooldownlado = 3;
	this->lado = true;
	this->dispararlaser = false;
	this->countdown_mov = 120;
	this->tipo_mov = 0;
	this->dy = this->dx = 1;
	if (t == 0) tipoavispa = Roja;
	if (t == 1) tipoavispa = Verde;
	if (t == 2) tipoavispa = Azul;

	this->figura = string(1, 157) + string(1, 179) + string(1, 157);
	this->x = x;
	this->y = y;
}
void Avispa::mover(Direccion direc) {
	if (tipo_mov > 8 && cooldownlado <= 0) {
		if (x + dx >= 90 || x - dx <= 20) {
			lado = !lado;
			cooldownlado = 6;
		}
	}
	switch (direc)
	{
	case Arriba:
		y -= dy;
		break;
	case Abajo:
		y += dy;
		break;
	case Derecha:
		x += dx;
		break;
	case Izquierda:
		x -= dx;
		break;
	}
	cooldownlado--;
}
void Avispa::mostrar() {
	switch (tipoavispa) {
	case 0:
		Console::ForegroundColor = ConsoleColor::Red;
		break;
	case 1:
		Console::ForegroundColor = ConsoleColor::Green;
		break;
	case 2:
		Console::ForegroundColor = ConsoleColor::Blue;
		break;
	};
	
	gotoxy(x, y);
	cout << figura;
}
void Avispa::borrar() {
	gotoxy(x, y);
	cout << "   ";
}
void Avispa::patronmovimiento() {
	if (countdown_mov>= 0)countdown_mov--;
	switch (tipoavispa) {
	case 0:
		if (tipo_mov >= 9) {
			dispararlaser = true;
			if (lado) {
				mover(Derecha);
			}
			else {
				mover(Izquierda);
			}
		}
		else {
			if (tipo_mov == 0 && countdown_mov > limite_mov) {
				mover(Derecha);
			}
			else if (tipo_mov == 1 && countdown_mov > limite_mov) {
				mover(Arriba);
				mover(Derecha); mover(Derecha);
			}
			else if (tipo_mov == 2 && countdown_mov > limite_mov) {
				mover(Arriba);
			}
			else if (tipo_mov == 3 && countdown_mov > limite_mov) {
				mover(Arriba);
				mover(Izquierda); mover(Izquierda);
			}
			else if (tipo_mov == 4 && countdown_mov > limite_mov) {
				mover(Izquierda); mover(Izquierda);
			}
			else if (tipo_mov == 5 && countdown_mov > limite_mov) {
				mover(Abajo);
				mover(Izquierda); mover(Izquierda);
			}
			else if (tipo_mov == 6 && countdown_mov > limite_mov) {
				mover(Abajo);
			}
			else if (tipo_mov == 7 && countdown_mov > limite_mov) {
				mover(Abajo);
				mover(Derecha); mover(Derecha);
			}
			else if (tipo_mov == 8 && countdown_mov > limite_mov) {
				mover(Derecha); 
				mover(Arriba);
			}
			if (countdown_mov == limite_mov && tipo_mov % 2 == 0) {
				tipo_mov++;
				limite_mov -= 4;
			}
			else if (countdown_mov == limite_mov && tipo_mov % 2 != 0) {
				tipo_mov++;
				if (tipo_mov == 8) limite_mov -= 8;
				limite_mov -= 8;
			}
		}
		break;
	case 1:
		if (tipo_mov >= 9) {
			dispararlaser = true;
			if (lado) {
				mover(Izquierda);
			}
			else {
				mover(Derecha);
			}
		}
		else {
			if (tipo_mov == 0 && countdown_mov > limite_mov) {
				mover(Izquierda); 
			}
			else if (tipo_mov == 1 && countdown_mov > limite_mov) {
				mover(Arriba);
				mover(Izquierda); mover(Izquierda);
			}
			else if (tipo_mov == 2 && countdown_mov > limite_mov) {
				mover(Arriba);
			}
			else if (tipo_mov == 3 && countdown_mov > limite_mov) {
				mover(Arriba);
				mover(Derecha); mover(Derecha);
			}
			else if (tipo_mov == 4 && countdown_mov > limite_mov) {
				mover(Derecha); mover(Derecha);
			}
			else if (tipo_mov == 5 && countdown_mov > limite_mov) {
				mover(Abajo);
				mover(Derecha); mover(Derecha);
			}
			else if (tipo_mov == 6 && countdown_mov > limite_mov) {
				mover(Abajo);
			}
			else if (tipo_mov == 7 && countdown_mov > limite_mov) {
				mover(Abajo);
				mover(Izquierda); mover(Izquierda);
			}
			else if (tipo_mov == 8 && countdown_mov > limite_mov) {
				mover(Izquierda); 
				mover(Arriba);
			}
			if (countdown_mov == limite_mov && tipo_mov % 2 == 0) {
				tipo_mov++;
				limite_mov -= 4;
			}
			else if (countdown_mov == limite_mov && tipo_mov % 2 != 0) {
				tipo_mov++;
				if (tipo_mov == 8) limite_mov -= 4;
				limite_mov -= 8;
			}
		}
	}

}