#include "../include/gridManagement.h"
#include "../include/movementManagement.h"

int main() {
  int sizeGrid = 10;
  char **gameGrid = initGrid(sizeGrid);

  char lastKey = '\0';
  UserKeybinds userKeys = setUserKeys();
  Snake userSnake;
  userSnake.x = 5;
  userSnake.y = 5;

  printf("\033[2J\033[H");

  enableTerminalRaw();

  while (1) {
    int key = readKey();

    if (key != NO_KEY_PRESSED) {
      if (key == EXIT_KEY)
        break;
      lastKey = key;
      moveSnake(gameGrid, &userSnake, sizeGrid, key, userKeys);

    } else {
      moveSnake(gameGrid, &userSnake, sizeGrid, lastKey, userKeys);
    }

    printf("\033[2J\033[H"); // Clear screen and move cursor to top-left
    printGrid(gameGrid, sizeGrid);
    if (snakeReachedBorder(userSnake, sizeGrid) == 1) {
      break;
    }
    fflush(stdout); // Console refresh immediate

    usleep(250000); // 250 ms
  }

  disableTerminalRaw();

  freeGrid(gameGrid, sizeGrid);
  return 0;
}
