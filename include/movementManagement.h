#ifndef MOVE_MANAGEMENT_H
#define MOVE_MANAGEMENT_H

#include "../include/keyManagement.h"

#define BODY_MAX 100

typedef struct Body {
  int x;
  int y;
} Body;

typedef struct Snake {
  int x;
  int y;
  int lenght;
  float score;
  Body body[BODY_MAX];

} Snake;

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys);

int snakeReachedBorder(Snake snake, int gridSize);
int snakeEatApple(char **grid, Snake snake);
void printSnakeInfo(Snake snake);

#endif