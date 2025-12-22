#include "../include/gridManagement.h"
#include "../include/movementManagement.h"

int main() {
  int sizeGrid = 10;
  char **gameGrid = initGrid(sizeGrid);

  UserKeybinds userKeys = setUserKeys();
  Snake userSnake;
  userSnake.x = 5;
  userSnake.y = 5;

  printf("\033[2J\033[H");

  enableTerminalRaw();

  while (1) {
    int key = readKey();
    if (key != -1) {
      if (key == 'm')
        break;

      moveSnake(gameGrid, &userSnake, sizeGrid, key, userKeys);
      printf("\033[2J\033[H");
      fflush(stdout);
      printGrid(gameGrid, sizeGrid);
    }

    usleep(50000); // 50 ms
  }

  disableTerminalRaw();

  freeGrid(gameGrid, sizeGrid);

  return 0;
}
