#include "../include/colorConsole.h"
#include "../include/gridManagement.h"
#include "../include/movementManagement.h"
#include "../include/saveLoadSystem.h"
#include "../include/snakeManagement.h"

int main() {
  srand(time(NULL));

  int sizeGrid = 15;
  char **gameGrid = initGrid(sizeGrid);
  int refreshTime = 350000; // 350ms

  int timeCounter = 0;
  int key = 0;

  char lastKey = '\0';
  UserKeybinds userKeys = setUserKeys();
  Snake userSnake = initSnake(SAVE_PATH);

  printf("\033[2J\033[H"); // Clear screen and move cursor to top-left
  printf("\n\n");
  enableTerminalRaw();

  while (1) {
    key = readKey();

    if (keyAmongUserBindings(key, userKeys) == 1) {
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

    if (timeCounter >= (8)) {
      spawnApple(gameGrid, sizeGrid);
      timeCounter = 0;
    }

    fflush(stdout); // refresh immediately the console

    if (userSnake.hit == HIT) {
      printf(RED "HIT!" RESET);
      break;
    }

    usleep(refreshTime);
    timeCounter++;
  }

  disableTerminalRaw();
  userSnake.bestScore = userSnake.score;
  saveGame(SAVE_PATH, userSnake);

  freeGrid(gameGrid, sizeGrid);
  return 0;
}