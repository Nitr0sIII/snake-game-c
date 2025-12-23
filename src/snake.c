#include "../include/gridManagement.h"
#include "../include/movementManagement.h"

int main() {
  srand(time(NULL));

  int sizeGrid = 15;
  int refreshTime = 250000; // 250ms
  char **gameGrid = initGrid(sizeGrid);
  int timeCounter = 0;

  char lastKey = '\0';
  UserKeybinds userKeys = setUserKeys();
  Snake userSnake;
  userSnake.x = 5;
  userSnake.y = 5;
  userSnake.lenght = 0;
  userSnake.score = 0.0f;

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

    if (timeCounter >= (8)) {
      spawnApple(gameGrid, sizeGrid);
      timeCounter = 0;
    }

    printSnakeInfo(userSnake);

    fflush(stdout); // Console refresh immediate

    if (snakeReachedBorder(userSnake, sizeGrid) == 1) {
      printf("border reached!");
      break;
    }

    usleep(refreshTime); // 250 ms
    timeCounter++;
  }

  disableTerminalRaw();

  freeGrid(gameGrid, sizeGrid);
  return 0;
}
