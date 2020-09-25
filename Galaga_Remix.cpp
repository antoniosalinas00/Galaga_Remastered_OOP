#include "Juego.h"
#include <iostream>


int main()
{
    srand(time(NULL));
    Console::CursorVisible = false;
    Juego* juego = new Juego();
    juego->jugar();

}
