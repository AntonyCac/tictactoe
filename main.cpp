

#include <iostream>
using namespace std;

bool turno = true;

char table[][3] = {
    {'_', '_', '_'},
    {'_', '_', '_'},
    {'_', '_', '_'}
};

char playerWin(){
    if(table[0][0] == table[0][1] && table[0][1] == table[0][2] && table[0][0] != '_'){
        return table[0][0];
    }
    if(table[1][0] == table[1][1] && table[1][1] == table[1][2] && table[1][0] != '_'){
        return table[1][0];
    }
    if(table[2][0] == table[2][1] && table[2][1] == table[2][2] && table[2][0] != '_'){
        return table[2][0];
    }
    if(table[0][0] == table[1][0] && table[1][0] == table[2][0] && table[0][0] != '_'){
        return table[0][0];
    }
    if(table[0][1] == table[1][1] && table[1][1] == table[2][1] && table[0][1] != '_'){
        return table[0][1];
    }
    if(table[0][2] == table[1][2] && table[1][2] == table[2][2] && table[0][2] != '_'){
        return table[0][2];
    }
    if(table[0][0] == table[1][1] && table[1][1] == table[2][2] && table[0][0] != '_'){
        return table[0][0];
    }
    if(table[0][2] == table[1][1] && table[1][1] == table[2][0] && table[0][2] != '_'){
        return table[0][2];
    }
    return '_';
}

void printTable() {
    char jugador = turno ? 'X' : 'O';
    int fila = 0;
    int columna = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << table[i][j] << " ";
        }
        cout << endl;
    }
    cout << "Escoge una fila: " ;
    cin >> fila;
    cout << "Escoge una columna: " ;
    cin >> columna;
    if (table[fila][columna] == '_') {
        table[fila][columna] = jugador;
        turno = !turno;
    } else {
        cout << "Esa casilla ya esta ocupada " << endl;
    } if (turno) {
        cout << "Turno del jugador X" << endl;
    } else {
        cout << "Turno del jugador O" << endl;
    }
    //ganador
    {
        char ganador = playerWin();
        if (ganador != '_') {
            cout << "El ganador es: " << ganador << endl;
        }
    }
}

int main(int argc, char const *argv[]) {
    while (playerWin() == '_') {
        printTable();
    }
    cout << "El jugador " << playerWin() << " ha ganado" << endl;
    return 0;
}