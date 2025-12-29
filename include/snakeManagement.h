#ifndef SNAKE_MANAGEMENT_H
#define SNAKE_MANAGEMENT_H

#include "../include/colorConsole.h"

#define BODY_MAX 100

typedef enum { HIT = 0, NO_HIT } Colision;

typedef struct Body {
  int x;
  int y;
} Body;

typedef struct Snake {
  int x;
  int y;
  float score;
  float bestScore;
  int bodyLength;
  Colision hit;
  Body body[BODY_MAX];
} Snake;

Snake initSnake(char *path);
void updateBestScore(Snake *snake);
void printSnakeInfo(Snake snake);

#endif