
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define FALSE 0
#define TRUE 1

void print_map(char **map2d) {
    for (int i = 0; i < 10; i++) {
        printf("%d %s\n", i, map2d[i]);
    }
}
bool isClosedByOne(char **map2d, int x, int y, bool **visited) {
    // Verificar límites y si el punto es '1'
    if (x < 0 || y < 0 || x >= 25 || y >= 10 || map2d[y][x] == '1')
        return FALSE;

    // Si el punto ya fue visitado, evitar ciclos infinitos
    if (visited[y][x])
        return TRUE;

    visited[y][x] = true; // Marcar como visitado

    // Explorar en todas las direcciones
    bool closedRight = (x == 24) || isClosedByOne(map2d, x + 1, y, visited);
    bool closedLeft = (x == 0) || isClosedByOne(map2d, x - 1, y, visited);
    bool closedDown = (y == 9) || isClosedByOne(map2d, x, y + 1, visited);
    bool closedUp = (y == 0) || isClosedByOne(map2d, x, y - 1, visited);

    // Si está cerrado en todas las direcciones, entonces el punto está completamente rodeado por '1'
    return closedRight && closedLeft && closedDown && closedUp;
}
int main() 
{
    char **map2d;

    map2d = (char**)malloc(10*sizeof(char *));
    // Inicializar el mapa
    map2d[0] = strdup("111111111111111111111111");
    map2d[1] = strdup("1000000000000000000000001");
    map2d[2] = strdup("1000000000000000000000001");
    map2d[3] = strdup("1000000000000000000000001");
    map2d[4] = strdup("1000000000000000000000001");
    map2d[5] = strdup("1000000000000000000000001");
    map2d[6] = strdup("1000000000000000000000001");
    map2d[7] = strdup("1000000000000000000000001");
    map2d[8] = strdup("1111101111111111111111111");
    map2d[9] = NULL;

     // Crear una matriz de visitados
    bool **visited = (bool **)calloc(10, sizeof(bool *));
    for (int i = 0; i < 10; i++) {
        visited[i] = (bool *)calloc(25, sizeof(bool));
    }
    printf("%ld\n",strlen(map2d[1]));
    //print_map(map2d);

    bool closed = isClosedByOne(map2d, 5, 5, visited);
    
     for (int i = 0; i < 10; i++)
     {
        free(map2d[i]);
        //free(visited[i]);
    }
    free(map2d);
}

