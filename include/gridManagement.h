#ifndef GRID_MANAGEMENT_H
#define GRID_MANAGEMENT_H

#include "../include/movementManagement.h"

#include <stdio.h>
#include <stdlib.h>

char **initGrid(int size);
void assignSnakeHead(char **grid, Snake snake);
void printGrid(char **grid, int size);
void freeGrid(char **grid, int size);

#endif