#include "../include/gridManagement.h"
#include "../include/movementManagement.h"
#include "../include/snakeManagement.h"

int main() {
  srand(time(NULL));

  int sizeGrid = 15;
  int refreshTime = 350000; // 350ms
  char **gameGrid = initGrid(sizeGrid);
  int timeCounter = 0;
  int key = 0;

  char lastKey = '\0';
  UserKeybinds userKeys = setUserKeys();
  Snake userSnake = initSnake();

  printf("\033[2J\033[H"); // Clear screen and move cursor to top-left
  enableTerminalRaw();

  while (1) {
    key = readKey();

    if (key != NO_KEY_PRESSED) {
      if (key == EXIT_KEY)
        break;
      lastKey = key;
      moveSnake(gameGrid, &userSnake, sizeGrid, key, userKeys);
    } else {
      moveSnake(gameGrid, &userSnake, sizeGrid, lastKey, userKeys);
    }

    printf("\033[2J\033[H");
    printGrid(gameGrid, sizeGrid);
    printSnakeInfo(userSnake);

    if (timeCounter >= (1)) {
      spawnApple(gameGrid, sizeGrid);
      timeCounter = 0;
    }

    fflush(stdout); // refresh immediately the console

    if (userSnake.hit == HIT) {
      printf("HIT!");
      break;
    }

    usleep(refreshTime);
    timeCounter++;
  }

  disableTerminalRaw();

  freeGrid(gameGrid, sizeGrid);
  return 0;
}