#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void imprimirTablero(char t[3][3]) {
    printf("\n   0   1   2\n");
    for (int i = 0; i < 3; i++) {
        printf("%d ", i);
        for (int j = 0; j < 3; j++) {
            if (t[i][j] == '\0') printf("( )");
	    else if (t[i][j] == 'X') printf("(X)");
	    else if (t[i][j] == 'O') printf("(O)");

            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n  ---+---+---\n");
        else printf("\n");
    }
}

int hayGanador(char t[3][3], char p) {
    for (int i = 0; i < 3; i++) {
        if (t[i][0] == p && t[i][1] == p && t[i][2] == p) return 1;
        if (t[0][i] == p && t[1][i] == p && t[2][i] == p) return 1;
    }
    if (t[0][0] == p && t[1][1] == p && t[2][2] == p) return 1;
    if (t[0][2] == p && t[1][1] == p && t[2][0] == p) return 1;
    return 0;
}

int tableroLleno(char t[3][3]) {
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (t[i][j] == '\0') return 0;
    return 1;
}

void jugarComp(char t[3][3]) {
    int f, c;
    do {
        f = rand() % 3;
        c = rand() % 3;
    } while (t[f][c] != '\0');

    t[f][c] = 'X';
    printf("\nLa computadora jugó en [%d, %d]\n", f, c);
}

void jugarPersona(char t[3][3]) {
    int f, c;
    do {
        printf("\nTu turno (fila columna): ");
        scanf("%d %d", &f, &c);
        if (f < 0 || f >= 3 || c < 0 || c >= 3)
            printf("Coordenadas inválidas. Usa números 0,1,2.\n");
        else if (t[f][c] != '\0')
            printf("Casilla ocupada. Elige otra.\n");
    } while (f < 0 || f >= 3 || c < 0 || c >= 3 || t[f][c] != '\0');

    t[f][c] = 'O';
}

int main() {
    char tablero[3][3] = { {'\0','\0','\0'}, {'\0','\0','\0'}, {'\0','\0','\0'} };
    srand(time(NULL));
    printf("El que lo lea es gay owo\n");
    printf("Estoy oxidado, deberia demorarme como máximo 20 minutos, llevo  3 horas\n");
    printf("XD\nXD\nXD\n");
    while (1) {
        imprimirTablero(tablero);
        jugarComp(tablero);
        if (hayGanador(tablero, 'X')) { imprimirTablero(tablero); printf("\nLa computadora gana.\n"); break; }
        if (tableroLleno(tablero)) { imprimirTablero(tablero); printf("\nEmpate.\n"); break; }

        imprimirTablero(tablero);
        jugarPersona(tablero);
        if (hayGanador(tablero, 'O')) { imprimirTablero(tablero); printf("\n¡Ganaste!\n"); break; }
        if (tableroLleno(tablero)) { imprimirTablero(tablero); printf("\nEmpate.\n"); break; }
    }

    return 0;
}

