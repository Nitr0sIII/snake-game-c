#ifndef GRID_MANAGEMENT_H
#define GRID_MANAGEMENT_H

#include "../include/movementManagement.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SNAKE_HEAD 'O'
#define SNAKE_BODY 'o'
#define APPLE_CELL '@'
#define BORDER_CELL '#'
#define EMPTY_CELL ' '

void spawnApple(char **grid, int size);
int cellAlreadyUsed(char **grid, char key, int size, int x, int y);
char **initGrid(int size);
void printGrid(char **grid, int size);
void freeGrid(char **grid, int size);

#endif