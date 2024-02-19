#include <stdio.h>
#include <stdlib.h>

#define MAX(a, b) ((a) > (b) ? (a) : (b))

int countArea(int x, int y, int **matrix, int n, int m)
{
    if (x >= n || x < 0 || y >= m || y < 0)
        return 0;
    if (matrix[x][y] != 1)
        return 0;
    matrix[x][y] = 2;
    return (1 + countArea(x + 1, y, matrix, n, m) + countArea(x - 1, y, matrix, n, m)
             + countArea(x, y + 1, matrix, n, m) + countArea(x, y - 1, matrix, n, m));
}

int main() 
{
  int n, m;
  scanf("%d %d", &n, &m);
  int **matrix = (int **)malloc(sizeof(int*) * n);
  for (int i = 0; i < n; i++) {
      matrix[i] = (int *)malloc(sizeof(int) * m);
      for(int j = 0; j < m; j++) {
          scanf("%d", &matrix[i][j]);
      }
  }
    int max_area = 0;
  for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
          if (matrix[i][j] == 1) {
              int area = countArea(i, j, matrix, n, m);
              max_area = MAX(max_area, area);
          }
      }
  }
  printf("%d", max_area);
  return 0;
}