#include <stdio.h>

#define M 10
#define N 10

void floodFillUtil(char pantalla[M][N], int x, int y, char prevC, char nuevoC) {
    // Verifica si la posición x, y está fuera de la pantalla o si el color no es el previo
    if (x < 0 || x >= M || y < 0 || y >= N)
        return;
    if (pantalla[x][y] != prevC)
        return;

    // Reemplaza el color en (x, y)
    pantalla[x][y] = nuevoC;

    // Recursivamente llama para los cuatro vecinos
    floodFillUtil(pantalla, x+1, y, prevC, nuevoC);
    floodFillUtil(pantalla, x-1, y, prevC, nuevoC);
    floodFillUtil(pantalla, x, y+1, prevC, nuevoC);
    floodFillUtil(pantalla, x, y-1, prevC, nuevoC);
}

void floodFill(char pantalla[M][N], int x, int y, char nuevoC) {
    char prevC = pantalla[x][y];
    floodFillUtil(pantalla, x, y, prevC, nuevoC);
}

int main() {
    char pantalla[M][N] = {
        {'Y', 'Y', 'Y', 'Y', 'X', 'Y', 'Y', 'Y', 'Y', 'Y'},
        {'Y', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'Y'},
        {'Y', 'X', 'Y', 'Y', 'X', 'Y', 'Y', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'X', 'X', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'Y', 'Y', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'Y', 'Y', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'X', 'X', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'X', 'Y'},
        {'Y', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'Y'},
        {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'}
    };

    floodFill(pantalla, 4, 4, 'C');

    // Imprime la pantalla
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", pantalla[i][j]);
        printf("\n");
    }

    return 0;
}