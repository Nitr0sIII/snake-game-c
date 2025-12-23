#include "../include/gridManagement.h"

void spawnApple(char **grid, int size) {
  int x, y;
  do {
    x = rand() % (size - 1);
    y = rand() % (size - 1);
  } while (cellAlreadyUsed(grid, size, x, y) != 1);

  grid[y][x] = '&';
}

int cellAlreadyUsed(char **grid, int size, int x, int y) {
  if (grid[y][x] != ' ') {
    return -1; // cell not empty
  }
  return 1; // cell empty
}

char **initGrid(int size) {
  char **gameGrid = malloc(size * sizeof(char *));

  for (int y = 0; y < size; y++) {
    gameGrid[y] = malloc(size * sizeof(char));
    for (int x = 0; x < size; x++) {
      if (y == 0 || y == size - 1 || x == 0 || x == size - 1) {
        gameGrid[y][x] = 'H';
      } else {
        gameGrid[y][x] = ' ';
      }
    }
  }

  return gameGrid;
}

void printGrid(char **grid, int size) {
  printf("\n");
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {

      printf(" %c ", grid[y][x]);
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
