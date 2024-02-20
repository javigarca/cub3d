#include <stdio.h>
#include <stdbool.h>
#define M 10
#define N 10


bool esPuntoCerrado(char matriz[M][N], int filas, int columnas, int x, int y) {
    if (x < 0 || x >= filas || y < 0 || y >= columnas || matriz[x][y] == '1') {
        return true;
    }
    if (x == 0 || x == filas - 1 || y == 0 || y == columnas - 1) {
        return false;
    }
    matriz[x][y] = '1'; // Marcamos el punto actual como visitado
    // Verificamos todas las direcciones
    bool arriba = esPuntoCerrado(matriz, filas, columnas, x - 1, y);
    bool abajo = esPuntoCerrado(matriz, filas, columnas, x + 1, y);
    bool izquierda = esPuntoCerrado(matriz, filas, columnas, x, y - 1);
    bool derecha = esPuntoCerrado(matriz, filas, columnas, x, y + 1);
    return arriba && abajo && izquierda && derecha;
}

int main() {
    char pantalla[M][N] = {
        {'1', '1', '1', '1', '0', '1', '1', '1', '1', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '0', '1', '1', '0', '1', '1', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '1', '1', '0', '1', '0', '1'},
        {'1', '0', '1', '0', '0', '0', '0', '1', '0', '1'},
        {'1', '0', '1', '1', '1', '1', '1', '1', '0', '1'},
        {'1', '0', '0', '0', '0', '0', '0', '0', '0', '1'},
        {'1', '1', '1', '1', '1', '1', '1', '1', '1', '1'}
    };

	if (esPuntoCerrado(pantalla, 10,10,2,2))
		printf("Es cerrado\n");
	else
		printf("Es abierto\n");
    return (0);
}