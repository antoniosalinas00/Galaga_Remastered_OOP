#pragma once

#include <iostream>
#include <string>
#include <conio.h>

using namespace std;
using namespace System;


void gotoxy(int x, int y) {
	Console::SetCursorPosition(x, y);
}
enum Direccion {
	Arriba,
	Abajo,
	Derecha,
	Izquierda
};

class Objeto {
protected:
	int x, y, dx, dy;
	string figura;

public:
	Objeto();
	virtual void mostrar();
	virtual void borrar();
	virtual void mover();
	int getx(), gety(), getdx(), getdy();
	void setx(int), sety(int), setdx(int), setdy(int);
	string getfigura() {
		return figura;
	}
};
Objeto::Objeto(){

}
void Objeto::mostrar() {

}
void Objeto::borrar() {

}
void Objeto::mover() {

}

int Objeto::getx() {
	return x;
}
int Objeto::gety() {
	return y;
}
int Objeto::getdx() {
	return dx;
}
int Objeto::getdy() {
	return dy;
}

void Objeto::setx(int x) {
	this->x = x;
}
void Objeto::sety(int y) {
	this->y = y;
}
void Objeto::setdx(int dx) {
	this->dx = dx;
}
void Objeto::setdy(int dy) {
	this->dy = dy;
}