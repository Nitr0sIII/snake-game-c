#ifndef MOVE_MANAGEMENT_H
#define MOVE_MANAGEMENT_H

#include "../include/keyManagement.h"

typedef struct Snake {
  int x;
  int y;
  int lenght;
  float score;
} Snake;

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys);
#endif