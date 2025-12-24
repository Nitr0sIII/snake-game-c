#ifndef SNAKE_MANAGEMENT_H
#define SNAKE_MANAGEMENT_H

#define BODY_MAX 100

typedef struct Body {
  int x;
  int y;
} Body;

typedef struct Snake {
  int x;
  int y;
  float score;
  int bodyLength;
  Body body[BODY_MAX];
} Snake;

Snake initSnake();

#endif