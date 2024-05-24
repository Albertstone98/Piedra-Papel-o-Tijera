#include <iostream>
#include <random>
#include <ctime>
#include <string>
using namespace std;

// Prototipos
void unJugador(string &, string &, int &, int &);
int ronda(string &, string &);
void mostrarOpcion(string &, int &);
int winRound(int &, int &);
int obtenerRandom();
void mostrarGanador(string &, string &, int &, int &);

void dosJugadores(string &, string &, int &, int &);

void ultimaPartida(string &, string &, int &, int &);

//  Play Game: Player vs CPU
void unJugador(string &playerName, string &player2Name, int &pointsP1, int &pointsP2){
    // Seteo en 0 de Puntajes
    pointsP1 = pointsP2 = 0;

    // Variables para Juego
    int turnos, rondaGanada;
    
    //  Nombre Player 1
    cout << "Ingresa tu nombre: ";
    cin >> playerName;
    player2Name = "CPU";
    system("cls");

    // Cantidad de Turnos
    cout << "¿Cuantos Turnos? ";
    cin >> turnos;

    //  Configuración de los Turnos
    for(int i = 1; i <= turnos; i++){
        // Jugamos una ronda
        rondaGanada = ronda(playerName, player2Name);

        // Si rondaGanada retorna 1, ganó Jugador 1. Si retorna 2, ganó Jugador 2. Si retorna 3, fue Empate.
        if(rondaGanada == 1){
            pointsP1++;
        }
        else if(rondaGanada == 2){
            pointsP2++;
        }
    }

    //  Averiguo quién Ganó la Partida.
    system("cls");
    mostrarGanador(playerName, player2Name, pointsP1, pointsP2);
}

//  Play Game: Player vs Player
void dosJugadores(string &playerName, string &player2Name, int &pointsP1, int &pointsP2){
    // Seteo en 0 de Puntajes
    pointsP1 = pointsP2 = 0;

    // Variables para Juego
    int turnos, rondaGanada;
    
    //  Nombre Player 1
    cout << "Ingresa Nombre Jugador 1: ";
    cin >> playerName;
    system("cls");

    // Nombre Player 2
    cout << "Ingresa Nombre Jugador 2: ";
    cin >> player2Name;
    system("cls");

    // Cantidad de Turnos
    cout << "¿Cuantos Turnos? ";
    cin >> turnos;

    //  Configuración de los Turnos
    for(int i = 1; i <= turnos; i++){
        // Jugamos una ronda
        rondaGanada = ronda(playerName, player2Name);

        // Si rondaGanada retorna 1, ganó Jugador 1. Si retorna 2, ganó Jugador 2. Si retorna 3, fue Empate.
        if(rondaGanada == 1){
            pointsP1++;
        }
        else if(rondaGanada == 2){
            pointsP2++;
        }
    }

    //  Averiguo quién Ganó la Partida.
    system("cls");
    mostrarGanador(playerName, player2Name, pointsP1, pointsP2);
}

// Rondas
int ronda(string &jug1, string &jug2){
    
    int opc1, opc2, ganadorRonda;

    //  Ronda
    for(int i = 1; i <= 2; i++){
        system("cls");
        if(i==1){
            cout << "---------------------------------" << endl;
            cout << "   Turno del Jugador: " << jug1 << endl;
            cout << "---------------------------------" << endl;
            cout << endl;

            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << endl;

            cout << "¿Que eliges? ";
            cin >> opc1;
        }else if(jug2 == "CPU"){     // Esta Condicion dará verdadera cuando sea 1vsCPU
            opc2 = obtenerRandom();
        }
        else{
            cout << "---------------------------------" << endl;
            cout << "   Turno del Jugador: " << jug2 << endl;
            cout << "---------------------------------" << endl;
            cout << endl;

            cout << "1. Piedra" << endl;
            cout << "2. Papel" << endl;
            cout << "3. Tijera" << endl;
            cout << endl;

            cout << "¿Que eliges? ";
            cin >> opc2;
        }
    }

    //  Muestro Opciones Elegidas
    system("cls");
    mostrarOpcion(jug1, opc1);
    mostrarOpcion(jug2, opc2);
    cout << endl;
    system("pause > nul");

    // Evaluo quien ganó la ronda
    return ganadorRonda = winRound(opc1, opc2); 
}

// Muestra la Opción Elegida por el Jugador
void mostrarOpcion(string &player, int &option){
    cout << "---------------------------------" << endl;
    cout << "   Jugador: " << player << endl;
    cout << "---------------------------------" << endl;
    cout << endl;

    if(option==1){
        cout << "      ___________" << endl;
        cout << "_ _ _|      _____)__" << endl;
        cout << "               __ __)" << endl;
        cout << "                 ___)" << endl;
        cout << "                 ___)" << endl;
        cout << "- - -.______________)" << endl;
        cout << "       PIEDRA" << endl;
    }
    else if(option==2){
        cout << "      _____________" << endl;
        cout << "_ _ _|      _______)_______" << endl;
        cout << "                 __ _______)_" << endl;
        cout << "                 ____________)" << endl;
        cout << "                 ___________)" << endl;
        cout << "- - -.__________________)" << endl;
        cout << "       PAPEL" << endl;
    }
    else{
        cout << "      _____________" << endl;
        cout << "_ _ _|      _______)_______" << endl;
        cout << "                 __ _______)" << endl;
        cout << "                 ____)" << endl;
        cout << "                 ____)__" << endl;
        cout << "- - -.__________________)" << endl;
        cout << "       TIJERA" << endl;
    }
    cout << endl << endl;
}

// Muestra quién ganó la Ronda. O si hubo EMPATE.
int winRound(int &o1, int &o2){
    if (o1 == o2) {
        cout << "---------------------------------" << endl;
        cout << "       Es un empate." << endl;
        cout << "---------------------------------" << endl;
        system("pause > nul");
        return 3;
    } else if ((o1 == 1 && o2 == 3) || (o1 == 2 && o2 == 1) || (o1 == 3 && o2 == 2)) {
        cout << "---------------------------------" << endl;
        cout << "       El jugador 1 gana." << endl;
        cout << "---------------------------------" << endl;
        system("pause > nul");
        return 1;
    } else {
        cout << "---------------------------------" << endl;
        cout << "       El jugador 2 gana." << endl;
        cout << "---------------------------------" << endl;
        system("pause > nul");
        return 2;
    }
}

// Función para Obtener un número RANDOM
int obtenerRandom(){
    unsigned seed = time(0);
    srand(seed);

    // Generar un número aleatorio entre 1 y 3
    int numero_random = rand() % 3 + 1;
    return numero_random;
}

// Muestra quien ganó el juego
void mostrarGanador(string &playerName, string &player2Name, int &pointsP1, int &pointsP2){
    
    cout << "---------------------------------" << endl;
    cout << "          PUNTAJES          " << endl;
    cout << "---------------------------------" << endl;
    cout << playerName << " tuvo " << pointsP1 << " puntos." << endl;
    cout << player2Name << " tuvo " << pointsP2 << " puntos." << endl;

    if(pointsP1 == pointsP2){
        cout << "---------------------------------" << endl;
        cout << "          !HUBO EMPATE¡          " << endl;
        cout << "---------------------------------" << endl;
    }
    else if(pointsP1 > pointsP2){
        cout << "---------------------------------" << endl;
        cout << "          Gano " << playerName << endl;
        cout << "---------------------------------" << endl;
    }
    else{
        cout << "---------------------------------" << endl;
        cout << "          Gano " << player2Name << endl;
        cout << "---------------------------------" << endl;
    }
    system("pause > nul");
}

// Muestro resultado de la última Partida
void ultimaPartida(string &playerName, string &player2Name, int &pointsP1, int &pointsP2){
    
    // Pregunto que no tengan valores Nulos/Ceros
    if(playerName != " " && player2Name != " "){
        if(player2Name == "CPU"){
            cout << "   Fue una Partida: 1vsCPU " << endl;
            mostrarGanador(playerName, player2Name, pointsP1, pointsP2);
        }
        else{
            cout << "   Fue una Partida: 1vs1 " << endl;
            mostrarGanador(playerName, player2Name, pointsP1, pointsP2);
        }
    }
    else{
        cout << "---------------------------------" << endl;
        cout << "      Aún no hubo una Partida    " << endl;
        cout << "---------------------------------" << endl;
        system("pause > nul");
    }
}