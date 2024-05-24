#include <iostream>
#include <locale>
#include <windows.h>
#include "funciones.h"

using namespace std;

int main() {

    SetConsoleTitle(TEXT("Piedra, Papel, o Tijera"));

    //std::locale::global(std::locale("es_ES.utf8"));

    mainTheme();
    menuPrincipal();
    exitGame();
    return 0;
}