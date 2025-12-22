#include "../include/gridManagement.h"

char **initGrid(int size) {

  char **gameGrid = malloc(size * sizeof(char *));

  for (int i = 0; i < size; i++) {
    gameGrid[i] = malloc(size * sizeof(char));
    for (int j = 0; j < size; j++) {
      gameGrid[i][j] = ' ';
    }
  }

  return gameGrid;
}

void assignSnakeHead(char **grid, Snake snake) { grid[snake.y][snake.x] = 'O'; }

void printGrid(char **grid, int size) {
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
