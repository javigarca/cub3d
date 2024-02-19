#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct {
    char **map2d;
} t_data;

bool floor_fill(t_data *data, int x, int y, bool **visited, int start_x, int start_y) {
    if (x < 0 || y < 0 || x >= 28 || y >= 10 )
        return false; // Si está fuera de los límites o es una pared, salir
    if (data->map2d[y][x] == '1')
		return false;
    if (visited[y][x]) {
        // Se encontró una posición ya visitada, lo que indica un bucle cerrado
        return true;
    }

    visited[y][x] = true; // Marcar como visitado

    // Explorar en todas las direcciones
    bool has_loop = floor_fill(data, x + 1, y, visited, start_x, start_y);
    has_loop |= floor_fill(data, x - 1, y, visited, start_x, start_y);
    has_loop |= floor_fill(data, x, y + 1, visited, start_x, start_y);
    has_loop |= floor_fill(data, x, y - 1, visited, start_x, start_y);

    // Si se encuentra un bucle en cualquier dirección, detener la exploración
    if (has_loop)
        return true;

    // Si se llega de nuevo al punto de inicio, eso indica un bucle cerrado
    if (x == start_x && y == start_y)
        return true;

    return false;
}

int main() {
    t_data *data = (t_data *)malloc(sizeof(t_data));
    if (data == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        return 1;
    }

    data->map2d = (char **)malloc(10 * sizeof(char *));
    if (data->map2d == NULL) {
        fprintf(stderr, "Error de asignación de memoria\n");
        free(data);
        return 1;
    }

    // Inicializar el mapa
    data->map2d[0] = strdup("111111101111111111111111");
    data->map2d[1] = strdup("1000000000000000000000001");
    data->map2d[2] = strdup("1000000000000000000000001");
    data->map2d[3] = strdup("1000000000000000000000001");
    data->map2d[4] = strdup("1000000000000000000000001");
    data->map2d[5] = strdup("1000000000000000000000001");
    data->map2d[6] = strdup("1000000000000000000000001");
    data->map2d[7] = strdup("1000000000000000000000001");
    data->map2d[8] = strdup("1111111111111111111111111");
    data->map2d[9] = NULL;

    // Crear una matriz de visitados
    bool **visited = (bool **)calloc(10, sizeof(bool *));
    for (int i = 0; i < 10; i++) {
        visited[i] = (bool *)calloc(28, sizeof(bool));
    }

    // Verificar si hay un bucle cerrado desde (3, 4)
    bool has_loop = floor_fill(data, 3, 4, visited, 3, 4);

    if (has_loop)
        printf("Hay un bucle cerrado alrededor del punto (3, 4).\n");
    else
        printf("No hay un bucle cerrado alrededor del punto (3, 4).\n");

    // Liberar memoria
    for (int i = 0; i < 10; i++) {
        free(data->map2d[i]);
        free(visited[i]);
    }
    free(data->map2d);
    free(visited);
    free(data);

    return 0;
}
