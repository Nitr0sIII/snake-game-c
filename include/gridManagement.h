#ifndef GRID_MANAGEMENT_H
#define GRID_MANAGEMENT_H

#include "../include/movementManagement.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void spawnApple(char **grid, int size);
int cellAlreadyUsed(char **grid, int size, int x, int y);
char **initGrid(int size);
void printGrid(char **grid, int size);
void freeGrid(char **grid, int size);

#endif