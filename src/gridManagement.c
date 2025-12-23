#include "../include/gridManagement.h"

void spawnApple(char **grid, int size) {
  int x, y;
  do {
    x = rand() % (size - 1);
    y = rand() % (size - 1);
  } while (cellAlreadyUsed(grid, size, x, y) != 1);

  grid[x][y] = '&';
}

int cellAlreadyUsed(char **grid, int size, int x, int y) {
  if (grid[x][y] != ' ') {
    return -1; // cell not empty
  }
  return 1; // cell empty
}

char **initGrid(int size) {
  char **gameGrid = malloc(size * sizeof(char *));

  for (int i = 0; i < size; i++) {
    gameGrid[i] = malloc(size * sizeof(char));
    for (int j = 0; j < size; j++) {
      if (i == 0 || i == size - 1 || j == 0 || j == size - 1) {
        gameGrid[i][j] = 'H';
      } else {
        gameGrid[i][j] = ' ';
      }
    }
  }

  return gameGrid;
}

void printGrid(char **grid, int size) {
  printf("\n");
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < size; j++) {

      printf("[%c]", grid[i][j]);
    }
    printf("\n");
  }
}

void freeGrid(char **grid, int size) {
  for (int i = 0; i < size; i++) {
    free(grid[i]);
  }

  free(grid);
}
