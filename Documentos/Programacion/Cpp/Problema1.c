#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void Tablero(char tablero[3][3]){
	printf("\n 0  1  2 \n");
	for(int i=0;i<3;i++){
		for(int j=0;j<3;j++){
			printf("(%c)",tablero[i][j]);
		}
	printf("\n");
	}
}

int jugarComp(char tablero[3][3]){
	int fila,columna;
	do{
		fila = rand() %3;
		columna = rand() %3;
	} while (tablero[fila][columna] != '\0');
	tablero[fila][columna] = '(X)';
	printf("La computadora ha jugado en [%d,%d]\n",fila,columna);
}

int jugarPersona(char tablero[3][3]){
	int fila,columna;
	do {
		printf("Ingresa las coord. de tu movimiento");
		scanf("%d %d", &fila, &columna);
		if (fila <0 || fila >= 3 || columna <0 || columna >= 3){
			printf("Posición inválida, ingrese números entre 0 y 2");
		} else if ( tablero[fila][columna] == '(X)'){
			printf("Casilla ocupada, ingrese otra");
		}
	} while (fila <0 || fila >=3 || columna <0 || columna>=3 || tablero[fila][columna] == '(X)');
}

int main(){
	char a[3][3]={'\0'};
	Tablero(a);
	srand(time(NULL));
	int juegoterminado;
	while (!juegoterminado){
		Tablero(a);
		jugarComp(a);
		jugarPersona(a);
	}
}


