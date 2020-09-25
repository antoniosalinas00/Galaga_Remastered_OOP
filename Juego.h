#pragma once
#include "Nave.h"
#include "ArregloDisparo.h"
#include "ArregloAvispas.h"

class Juego {
private:
    char tecla;
    int nivel, vidas, score;
    int countdownjuego, cooldownsublife;
    int cooldownagregar, cooldownlaser;

    Nave* NaveJugador;
    Municion* disparoJugador;
    Municion* disparoEnemigos;
    ArregloAvispa* avispas;

public:
	Juego();

    void levelup();
	void jugar();
    void disparoenemigo();
    void colisiondisparos();
    bool colisionnave();
};

Juego::Juego() {
    nivel = 1;
    score = 0;
    countdownjuego = 300;
    cooldownagregar = 20;
    cooldownlaser = cooldownsublife = 5;
    vidas = 5;

    NaveJugador = new Nave();
    disparoJugador = new Municion();
    disparoEnemigos = new Municion();
    avispas = new ArregloAvispa();
}
void Juego::disparoenemigo() {
    srand(time(NULL));
    if (avispas->getavispas()->size() > 1) {
        int r = rand() % avispas->getavispas()->size();
        if (avispas->getavispas()->at(r)->getdispararlaser()) {
            disparoEnemigos->agregarbala(avispas->getavispas()->at(r)->getx(), avispas->getavispas()->at(r)->gety(), Abajo, enemigo);
        }
    }
}

void Juego::levelup() {
    if (score >= 50 && nivel ==1) {
        nivel++;
    }
    else if (score >= 100 && nivel == 2) {
        nivel++;
    }
}
void Juego::colisiondisparos() {
    //colission wasp and bullet
    for (int i = 1; i < avispas->getavispas()->size(); i++) {
        for (int j = 1; j < disparoJugador->getmunicion()->size(); j++) {
            if (disparoJugador->getmunicion()->at(j)->getx() >= avispas->getavispas()->at(i)->getx() -2 &&
                disparoJugador->getmunicion()->at(j)->getx() <= avispas->getavispas()->at(i)->getx() + 2) {
                if (disparoJugador->getmunicion()->at(j)->gety() == avispas->getavispas()->at(i)->gety()) {
                    disparoJugador->getmunicion()->at(j)->borrar();
                    disparoJugador->eliminarbala(j);
                    avispas->getavispas()->at(i)->borrar();
                    avispas->eliminaravispa(i);
                    score += 10;
                    break;
                }
            }
        }
    }

    //collision bullets
    for (int i = 1; i < disparoEnemigos->getmunicion()->size(); i++) {
        for (int j = 1; j < disparoJugador->getmunicion()->size(); j++) {
            if (disparoJugador->getmunicion()->at(j)->getx() >= disparoEnemigos->getmunicion()->at(i)->getx() - 1 &&
                disparoJugador->getmunicion()->at(j)->getx() <= disparoEnemigos->getmunicion()->at(i)->getx() + 1 &&
                disparoJugador->getmunicion()->at(j)->gety() == disparoEnemigos->getmunicion()->at(i)->gety()) {

                disparoJugador->getmunicion()->at(j)->borrar();
                disparoEnemigos->getmunicion()->at(i)->borrar();
                disparoEnemigos->eliminarbala(i);
                disparoJugador->eliminarbala(j);
                break;

            }
        }
    }
}

bool Juego::colisionnave() {
    for (int i = 1; i < disparoEnemigos->getmunicion()->size(); i++) {
        if (disparoEnemigos->getmunicion()->at(i)->getx() >= NaveJugador->getx() - 3 &&
            disparoEnemigos->getmunicion()->at(i)->getx() <= NaveJugador->getx() + 3 &&
            disparoEnemigos->getmunicion()->at(i)->gety() >= NaveJugador->gety()) {
            vidas--;
            NaveJugador->borrar();
            return true;
        }
    }
    return false;
}


void Juego::jugar() {
    tecla = 0;


    while (true) {
        gotoxy(2, 5);
        Console::ForegroundColor = ConsoleColor::Blue;
        cout << "Vidas = " << vidas;
        gotoxy(2, 3);
        cout << "Score = " << score;
        gotoxy(2, 1);
        cout << "Nivel = " << nivel;


        while (!_kbhit()) {
            colisiondisparos();
            NaveJugador->borrar();
            NaveJugador->mover(tecla);
            if (tecla == 32) {
                disparoJugador->agregarbala(NaveJugador->getx(), NaveJugador->gety(), Arriba, amigo);
            }
            if (cooldownagregar<= 0 && countdownjuego >= 100) {
                avispas->setagregar(true);
                if (avispas->getagregar()) {
                    avispas->agregaravispa(4, 20, 0);
                    avispas->agregaravispa(Console::WindowWidth - 1, 20, 1);
                    avispas->setagregar(false);
                }
                cooldownagregar = 30;
            }
            avispas->dibujar();
            disparoJugador->dibujar();
            disparoEnemigos->dibujar();

            NaveJugador->mostrar();
            Sleep(50);
            tecla = 0;
            if (cooldownsublife <= 0 && vidas > 0) {
                if (colisionnave()) cooldownsublife = 5;
            }
        }
        if (cooldownlaser <= 0) {
            disparoenemigo(); cooldownlaser = 5;
        }
        levelup();
        cooldownsublife--;
        cooldownlaser--;
        cooldownagregar--;
        countdownjuego--;
        tecla = _getch();

        if (nivel == 3) {
            gotoxy(Console::WindowWidth / 2, Console::WindowHeight / 2);
            Console::ForegroundColor = ConsoleColor::Green;
            cout << "YOU WIN";
            _getch();
        }
    }
}