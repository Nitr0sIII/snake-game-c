#ifndef MOVE_MANAGEMENT_H
#define MOVE_MANAGEMENT_H

#include "../include/colorConsole.h"
#include "../include/gridManagement.h"
#include "../include/keyManagement.h"
#include "../include/snakeManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys);
void increaseBody(Snake *snake, char key, UserKeybinds userKeys);
int snakeEatApple(char **grid, Snake snake);
int keyAmongUserBindings(char key, UserKeybinds bindings);
void printSnakeInfo(Snake snake);

#endif