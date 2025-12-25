#include "../include/gridManagement.h"
#include "../include/colorConsole.h"

void spawnApple(char **grid, int size) {
  int x, y;
  do {
    x = rand() % (size - 4) + 2;
    y = rand() % (size - 4) + 2;
  } while (cellAlreadyUsed(grid, EMPTY_CELL, size, x, y) != 1);

  grid[y][x] = APPLE_CELL;
}

int cellAlreadyUsed(char **grid, char key, int size, int x, int y) {
  if (grid[y][x] == key) {
    return 1; // cell used by "key"
  }
  return -1; //  cell not used by "key"
}

char **initGrid(int size) {
  char **gameGrid = malloc(size * sizeof(char *));

  for (int y = 0; y < size; y++) {
    gameGrid[y] = malloc(size * sizeof(char));
    for (int x = 0; x < size; x++) {
      if (y == 0 || y == size - 1 || x == 0 || x == size - 1) {
        gameGrid[y][x] = BORDER_CELL;
      } else {
        gameGrid[y][x] = EMPTY_CELL;
      }
    }
  }

  return gameGrid;
}

void printGrid(char **grid, int size) {
  printf("\n\n");
  for (int y = 0; y < size; y++) {
    for (int x = 0; x < size; x++) {
      char usedChar = grid[y][x];
      switch (usedChar) {
      case SNAKE_HEAD:
        printf(GRN " %c" RESET, grid[y][x]);
        break;
      case SNAKE_BODY:
        printf(GRN " %c" RESET, grid[y][x]);
        break;
      case APPLE_CELL:
        printf(RED " %c" RESET, grid[y][x]);
        break;
      case BORDER_CELL:
        printf(BLU " %c" RESET, grid[y][x]);
        break;
      default:
        printf(" %c", grid[y][x]);
        break;
      }
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
