#ifndef SAVE_LOAD_SYSTEM_H
#define SAVE_LOAD_SYSTEM_H

#define SAVE_PATH "./save.bin"

#include "../include/colorConsole.h"
#include "../include/snakeManagement.h"

#include <stdio.h>

void saveGame(char *path, Snake snake);

#endif