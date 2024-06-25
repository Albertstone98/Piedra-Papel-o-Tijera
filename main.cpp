#include <iostream>
#include <locale.h>
#include <stdio.h>
#include <windows.h>
#include "funciones.h"

using namespace std;

int main() {

    SetConsoleTitle(TEXT("Piedra, Papel, o Tijera"));
    setlocale(LC_ALL, "spanish");
    //sonidoPrueba1();
    mainTheme();
    menuPrincipal();
    exitGame();
    return 0;
}