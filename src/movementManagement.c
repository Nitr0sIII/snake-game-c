#include "../include/movementManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys) {
  int move[2] = {0, 0}; // y, x

  if (key == userKeys.up) {
    snake->y--;
    move[0] = -1;
    move[1] = 0;
  } else if (key == userKeys.down) {
    snake->y++;
    move[0] = 1;
    move[1] = 0;
  } else if (key == userKeys.left) {
    snake->x--;
    move[0] = 0;
    move[1] = -1;
  } else if (key == userKeys.right) {
    snake->x++;
    move[0] = 0;
    move[1] = 1;
  }

  if (snakeEatApple(grid, *snake) == 1) {
    snake->body[snake->lenght].x = snake->body[snake->lenght - 1].x - move[1];
    snake->body[snake->lenght].y = snake->body[snake->lenght - 1].y - move[0];

    snake->score += 5.0f;
    snake->lenght += 1;
  } else {
    if (snake->lenght > 0) {
      for (int i = snake->lenght - 1; i > 0; i--) {
        snake->body[i] = snake->body[i - 1];
      }
    }
  }

  if (snake->lenght > 0) {
    snake->body[0].x = snake->x - move[1];
    snake->body[0].y = snake->y - move[0];
  }

  for (int i = 0; i < gridSize; i++) {
    for (int j = 0; j < gridSize; j++) {
      if (grid[i][j] == 'c' || grid[i][j] == 'o') {
        grid[i][j] = ' ';
      }
    }
  }

  for (int i = 0; i < snake->lenght; i++) {
    grid[snake->body[i].y][snake->body[i].x] = 'c';
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

int snakeEatApple(char **grid, Snake snake) {
  if (grid[snake.y][snake.x] == '&') {
    return 1; // snake will eat an apple
  }
  return -1; // snake will not eat an apple
}

void printSnakeInfo(Snake snake) {
  printf("\n");

  printf("Lenght : %d\n", snake.lenght);
  printf("Score : %.2f\n", snake.score);
  printf("[%d] - [%d]", snake.x, snake.y);
}