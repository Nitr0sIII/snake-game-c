#ifndef MOVE_MANAGEMENT_H
#define MOVE_MANAGEMENT_H

#include "../include/keyManagement.h"
#include "../include/snakeManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys);
void increaseBody(Snake *snake, char key, UserKeybinds userKeys);
int snakeReachedBorder(Snake snake, int gridSize);
int snakeEatApple(char **grid, Snake snake);
void printSnakeInfo(Snake snake);

#endif