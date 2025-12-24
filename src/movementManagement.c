#include "../include/movementManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys) {

  grid[snake->y][snake->x] = ' ';

  int saveCoordinateX = snake->x;
  int saveCoordinateY = snake->y;

  if (key == userKeys.up) {
    snake->y--;
  } else if (key == userKeys.down) {
    snake->y++;
  } else if (key == userKeys.left) {
    snake->x--;
  } else if (key == userKeys.right) {
    snake->x++;
  }

  if (snakeEatApple(grid, *snake) == 1) {
    snake->score += 5;
    snake->bodyLength += 1;
    increaseBody(snake, key, userKeys, saveCoordinateY, saveCoordinateX);
  }

  if (snake->bodyLength > 0) {
    for (int i = snake->bodyLength; i > 0; i--) {
      snake->body[i].y = snake->body[i - 1].y;
      snake->body[i].x = snake->body[i - 1].x;
    }

    snake->body[0].x = saveCoordinateX;
    snake->body[0].y = saveCoordinateY;
  }

  if (snake->bodyLength > 0) {
    for (int y = 0; y < gridSize; y++) {
      for (int x = 0; x < gridSize; x++) {
        if (grid[y][x] == 'c') {
          grid[y][x] = ' ';
        }
      }
    }
  }

  if (snake->bodyLength > 0) {
    for (int i = 0; i < snake->bodyLength; i++) {
      grid[snake->body[i].y][snake->body[i].x] = 'c';
    }
  }

  grid[snake->y][snake->x] = 'o';
}

int snakeReachedBorder(Snake snake, int gridSize) {
  if (snake.x == 0 || snake.x == gridSize - 1 || snake.y == 0 ||
      snake.y == gridSize - 1) {
    return 1; // border reached
  }

  return -1; // border not reached
}

void increaseBody(Snake *snake, char key, UserKeybinds userKeys, int oldY,
                  int oldX) {
  if (snake->bodyLength <= 1) {
    if (key == userKeys.up) {
      snake->body[0].x = snake->x;
      snake->body[0].y = snake->y--;
    } else if (key == userKeys.down) {
      snake->body[0].x = snake->x;
      snake->body[0].y = snake->y++;
    } else if (key == userKeys.left) {
      snake->body[0].x = snake->x++;
      snake->body[0].y = snake->y;
    } else if (key == userKeys.right) {
      snake->body[0].x = snake->x--;
      snake->body[0].y = snake->y;
    }
  } else {
    if (key == userKeys.up) {
      snake->body[snake->bodyLength].x = snake->body[(snake->bodyLength) - 1].x;
      snake->body[snake->bodyLength].y = snake->body[snake->bodyLength - 1].y--;
    } else if (key == userKeys.down) {
      snake->body[snake->bodyLength].x = snake->body[snake->bodyLength - 1].x;
      snake->body[snake->bodyLength].y = snake->body[snake->bodyLength - 1].y++;
    } else if (key == userKeys.left) {
      snake->body[snake->bodyLength].x = snake->body[snake->bodyLength - 1].x++;
      snake->body[snake->bodyLength].y = snake->body[snake->bodyLength - 1].y;
    } else if (key == userKeys.right) {
      snake->body[snake->bodyLength].x = snake->body[snake->bodyLength - 1].x--;
      snake->body[snake->bodyLength].y = snake->body[snake->bodyLength - 1].y;
    }
  }
}

int snakeEatApple(char **grid, Snake snake) {
  if (grid[snake.y][snake.x] == '&') {
    return 1; // snake will eat an apple
  }
  return -1; // snake will not eat an apple
}

void printSnakeInfo(Snake snake) {
  printf("\n");

  printf("Lenght : %d\n", snake.bodyLength);
  printf("Score : %.2f\n", snake.score);
  printf("[%d] - [%d]\n", snake.x, snake.y);

  for (int i = 0; i < snake.bodyLength; i++) {
    printf("[%d][%d] - ", snake.body[i].y, snake.body[i].x);
  }
}