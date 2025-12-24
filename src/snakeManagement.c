#include "../include/snakeManagement.h"

Snake initSnake() {
  Snake newSnake;
  newSnake.x = 5;
  newSnake.y = 5;
  newSnake.bodyLength = 0;
  newSnake.score = 0.0f;
  newSnake.hit = NO_HIT;

  return newSnake;
}