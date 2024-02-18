#include <stdio.h>

int main() {
  int map[5][7] = {{1, 1, 1, 0, 1, 1, 1},
                   {1, 0, 1, 0, 1, 0, 1},
                   {1, 0, 1, 1, 1, 0, 1},
                   {1, 0, 0, 0, 0, 0, 1},
                   {1, 1, 1, 1, 1, 1, 1}};

  int i, j, closed = 1;

  // Recorrer el borde del mapa

  // Primera fila
  if (map[0][0] == 0 || map[0][1] == 0 || map[1][0] == 0 || map[1][1] == 0) {
    closed = 0;
    break;
  }

  for (j = 1; j < 4; j++) {
    if (map[0][j] == 0 && (map[0][j-1] == 0 || map[1][j] == 0)) {
      closed = 0;
      break;
    }
  }

  // Última columna
  for (i = 1; i < 4; i++) {
    if (map[i][3] == 0 && (map[i-1][3] == 0 || map[i][2] == 0)) {
      closed = 0;
      break;
    }
  }

  // Última fila
  if (map[3][3] == 0 || map[3][2] == 0 || map[2][3] == 0 || map[2][2] == 0) {
    closed = 0;
    break;
  }

  for (j = 2; j
