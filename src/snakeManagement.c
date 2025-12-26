#include "../include/snakeManagement.h"
#include <stdio.h>

Snake initSnake(char *path) {

  Snake newSnake;
  newSnake.x = 5;
  newSnake.y = 5;
  newSnake.bodyLength = 0;
  newSnake.score = 0.0f;
  newSnake.hit = NO_HIT;

  FILE *file = fopen(path, "rb");

  if (file == NULL) {
    newSnake.bestScore = 0.0f;
  } else {
    Snake saveSnake;
    fread(&saveSnake, sizeof(Snake), 1, file);
    newSnake.bestScore = saveSnake.bestScore;
    fclose(file);
  }

  return newSnake;
}