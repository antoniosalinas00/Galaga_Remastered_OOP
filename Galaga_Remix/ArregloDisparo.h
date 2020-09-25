#pragma once
#include "Disparo.h"
#include <vector>

class Municion {
private:
	vector<Disparo*>* municion;
public:
	Municion();
	void dibujar();
	void agregarbala(int, int, Direccion, tipo);
	void eliminarbala(int);
	vector<Disparo*>* getmunicion() {
		return municion;
	}
};
Municion::Municion(){
	municion = new vector<Disparo*>;
	Disparo* disparo = new Disparo(10, 10, Abajo, amigo);
	municion->push_back(disparo);
}
void Municion::agregarbala(int x, int y, Direccion dir, tipo dis) {
	Disparo* disparo = new Disparo(x, y, dir, dis);
	municion->push_back(disparo);
}
void Municion::eliminarbala(int pos) {
	municion->erase(municion->begin() + pos);
}
void Municion::dibujar() {

	for (int i = 1; i < municion->size(); i++) {
		municion->at(i)->borrar();
		municion->at(i)->mover();
		municion->at(i)->mostrar();

		if (municion->at(i)->gety() - municion->at(i)->getdy() <= 0 || municion->at(i)->gety() + municion->at(i)->getdy() >= Console::WindowHeight) {
			municion->at(i)->borrar();
			municion->erase(municion->begin() + i);
		}
	}
}