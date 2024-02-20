#include <stdio.h>
#include <stdbool.h>

#define M 10
#define N 10

bool isBorder(int x, int y) {
    return x == 0 || x == M-1 || y == 0 || y == N-1;
}

bool floodFillUtil(char pantalla[M][N], int x, int y, char prevC, char nuevoC, bool *isClosed) {
    // Verifica si la posición x, y está fuera de la pantalla o si el color no es el previo
    if (x < 0 || x >= M || y < 0 || y >= N)
        return false;
    if (pantalla[x][y] != prevC)
        return true;

    // Si llega al borde, la región no está cerrada
    if (isBorder(x, y)) {
        *isClosed = false;
    }

    // Marca la posición actual para evitar ciclos infinitos
    pantalla[x][y] = nuevoC;

    // Recursivamente llama para los cuatro vecinos
    floodFillUtil(pantalla, x+1, y, prevC, nuevoC, isClosed);
    floodFillUtil(pantalla, x-1, y, prevC, nuevoC, isClosed);
    floodFillUtil(pantalla, x, y+1, prevC, nuevoC, isClosed);
    floodFillUtil(pantalla, x, y-1, prevC, nuevoC, isClosed);

    return *isClosed;
}

bool floodFill(char pantalla[M][N], int x, int y, char nuevoC) {
    char prevC = pantalla[x][y];
    bool isClosed = true;
    floodFillUtil(pantalla, x, y, prevC, nuevoC, &isClosed);
    return isClosed;
}

int main() {
    // X PARED
    char pantalla[M][N] = {
        {'Y', 'Y', 'Y', 'Y', 'X', 'Y', 'Y', 'Y', 'Y', 'Y'},
        {'Y', 'Y', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'Y'},
        {'Y', 'Y', 'Y', 'Y', 'X', 'Y', 'Y', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'X', 'X', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'Y', 'Y', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'Y', 'Y', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'X', 'X', 'X', 'X', 'Y', 'X', 'Y'},
        {'Y', 'X', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'X', 'Y'},
        {'Y', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'X', 'Y'},
        {'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y', 'Y'}
    };

    bool isRegionClosed = floodFill(pantalla, 4, 4, 'C');
    printf("La region es cerrada? %s\n", isRegionClosed ? "Si" : "No");

    // Imprime la pantalla
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++)
            printf("%c ", pantalla[i][j]);
        printf("\n");
    }

    return 0;
}