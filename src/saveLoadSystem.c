#include "../include/saveLoadSystem.h"
#include "../include/snakeManagement.h"

void saveGame(char *path, Snake snake) {
  FILE *file = fopen(path, "wb");
  if (fwrite(&snake, sizeof(Snake), 1, file) != 1) {
    printf(RED "Error : unsaved\n" RESET);
  }
  fclose(file);
}
