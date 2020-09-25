#pragma once
#include "Avispa.h"
#include <vector>
#include <time.h>

class ArregloAvispa {
private:
	vector<Avispa*>* arregloAvispas;
	bool agregar;
public:
	ArregloAvispa();
	void dibujar();
	void agregaravispa(int, int, int);
	void eliminaravispa(int);
	void setagregar(bool);
	bool getagregar() {
		return agregar;
	}
	vector<Avispa*>* getavispas() {
		return arregloAvispas;
	}

};
ArregloAvispa::ArregloAvispa(){
	agregar = false;
	int r = rand() % 2;
	arregloAvispas = new vector<Avispa*>;
	Avispa* avispa = new Avispa(10, 10, r);
	arregloAvispas->push_back(avispa);
}
void ArregloAvispa::agregaravispa(int x, int y, int t) {
	Avispa* avispa = new Avispa(x, y, t);
	arregloAvispas->push_back(avispa);
}

void ArregloAvispa::setagregar(bool agregar) {
	this->agregar = agregar;
}
void ArregloAvispa::eliminaravispa(int pos) {
	arregloAvispas->erase(arregloAvispas->begin() + pos);
}
void ArregloAvispa::dibujar() {
	for (int i = 1; i < arregloAvispas->size(); i++) {
		arregloAvispas->at(i)->borrar();
		arregloAvispas->at(i)->patronmovimiento();
		arregloAvispas->at(i)->mostrar();

		if (arregloAvispas->at(i)->gety() - arregloAvispas->at(i)->getdy() <= 0 || 
			arregloAvispas->at(i)->getx() - arregloAvispas->at(i)->getdx() <= 0 || 
			arregloAvispas->at(i)->getx() + arregloAvispas->at(i)->getdx() >= Console::WindowWidth || 
			arregloAvispas->at(i)->gety() + arregloAvispas->at(i)->getdy() >= Console::WindowHeight   ) {
			arregloAvispas->at(i)->borrar();
			arregloAvispas->erase(arregloAvispas->begin() + i);
		} 
	}
}