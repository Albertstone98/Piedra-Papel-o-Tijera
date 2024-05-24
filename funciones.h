#include <iostream>
#include "juego.h"
using namespace std;

// Prototipos
void menuPrincipal();
void exitGame();
void mainTheme();
void mainTheme();
void ultimaPartida();

void mainTheme(){
    cout << "----------------------" << endl;
    cout << "|   PIEDRA           |" << endl;
    cout << "|       PAPEL        |" << endl;
    cout << "|           TIJERA   |" << endl;
    cout << "----------------------" << endl;
    system("pause > nul");
}

void menuPrincipal() {
    int opc;

    // Variables del Juego
    string jugadorUno = " ", jugadorDos = " ";
    int pointsP1 = 0, pointsP2 = 0;

    while(true){
        system("cls");

        cout << "------------------------------" << endl;
        cout << "       MENU PRINCIPAL" << endl;
        cout << "------------------------------" << endl;
        cout << endl;

        cout << "1 - Un Jugador" << endl;
        cout << "2 - Dos Jugadores" << endl;
        cout << "3 - Ultima Partida" << endl;
        cout << endl;
        cout << "------------------------------" << endl;
        cout << "0 - Salir" << endl;
        cout << endl;

        cout << "Ingrese Opcion: ";
        cin >> opc;

        switch (opc)
        {
        case 1:
            // Función para 1 Jugador
            system("cls");
            unJugador(jugadorUno, jugadorDos, pointsP1, pointsP2);
            break;
        case 2:
            // Función para 2 Jugadores
            system("cls");
            dosJugadores(jugadorUno, jugadorDos, pointsP1, pointsP2);
            break;
        case 3:
            // Función para ver Ultima Partida
            system("cls");
            ultimaPartida(jugadorUno, jugadorDos, pointsP1, pointsP2);
            break;
        case 0:
            return;
            break;      
        default:
            cout << "¡Opcion Incorrecta!" << endl;
            system("pause > nul");
            break;
        } 
    }
}

void exitGame(){
    system("cls");
    cout << "Gracias por Jugar!" << endl;
    cout << "Que tenga un buen dia." << endl;
    system("pause > nul");
    exit(0);
}