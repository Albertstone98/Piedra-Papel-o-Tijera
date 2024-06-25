#include <iostream>
#include "juego.h"

#include <conio.h>
#include <windows.h>
#include <mmsystem.h>

using namespace std;

// Prototipos
void menuPrincipal();
void exitGame();
void mainTheme();
void mainTheme();
void ultimaPartida();

void sonidoPrueba1(){
    //PlaySound(TEXT("juego.wav"),NULL,SND_SYNC);
}

void mainTheme(){
    cout << "------------------------" << endl;
    cout << "| |  PIEDRA          | |" << endl;
    cout << "| |      PAPEL       | |" << endl;
    cout << "| |          TIJERA  | |" << endl;
    cout << "------------------------" << endl;
    system("pause > nul");
}

void menuPrincipal() {
    int opc;

    // Variables del Juego
    string jugadorUno = " ", jugadorDos = " ";
    int pointsP1 = 0, pointsP2 = 0;

    while(true){
        system("cls");

        cout << BOLD << BLUE;
        cout << "|------------------------------|" << endl;
        cout << "|        " << CYAN << "MENU PRINCIPAL" << BLUE << "        |" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|    "<< GREEN <<"   1 - Un Jugador         "<< BLUE <<"|" << endl;
        cout << "|    "<< GREEN <<"   2 - Dos Jugadores      "<< BLUE <<"|" << endl;
        cout << "|    "<< GREEN <<"   3 - Ultima Partida     "<< BLUE <<"|" << endl;
        cout << "|------------------------------|" << endl;
        cout << "|    "<< RED <<"   0 - Salir              "<< BLUE <<"|" << endl;
        cout << "|------------------------------"<< BLUE <<"|" << endl;
        cout << endl;
        cout << "     "<< YELLOW <<"   Ingrese Opcion: " << RESET;;
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