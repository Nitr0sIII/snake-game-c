#include "../include/movementManagement.h"
#include "../include/gridManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys) {

  grid[snake->y][snake->x] = EMPTY_CELL; // clear the snake's head

  int saveCoordinateX = snake->x; // save orignal coordinate X
  int saveCoordinateY = snake->y; // save orignal coordinate Y

  // Move system
  if (key == userKeys.up) {
    snake->y--;
  } else if (key == userKeys.down) {
    snake->y++;
  } else if (key == userKeys.left) {
    snake->x--;
  } else if (key == userKeys.right) {
    snake->x++;
  }

  if (cellAlreadyUsed(grid, SNAKE_BODY, gridSize, snake->x, snake->y) == 1 ||
      cellAlreadyUsed(grid, BORDER_CELL, gridSize, snake->x, snake->y) == 1) {
    // if border or himself touch : dead
    snake->hit = HIT;
  }

  if (snakeEatApple(grid, *snake) == 1) {
    // if snake will eat an apple
    snake->score += 5;
    if (snake->bodyLength < BODY_MAX) {
      // only if the max size of the body is not reached
      snake->bodyLength += 1;
      increaseBody(snake, key, userKeys);
    }
  }

  if (snake->bodyLength > 0) {
    // if the snake have one body part
    for (int i = snake->bodyLength; i > 0; i--) {
      // moves each body's part towards the previous one, movement/tracking
      snake->body[i].y = snake->body[i - 1].y;
      snake->body[i].x = snake->body[i - 1].x;
    }

    snake->body[0].x = saveCoordinateX;
    snake->body[0].y = saveCoordinateY;
  }

  if (snake->bodyLength > 0) {
    // clear all body with : ' '
    for (int y = 0; y < gridSize; y++) {
      for (int x = 0; x < gridSize; x++) {
        if (grid[y][x] == SNAKE_BODY) {
          grid[y][x] = EMPTY_CELL;
        }
      }
    }
  }

  if (snake->bodyLength > 0) {
    // set with 'c' each body's part with coordinate
    for (int i = 0; i < snake->bodyLength; i++) {
      grid[snake->body[i].y][snake->body[i].x] = SNAKE_BODY;
    }
  }

  grid[snake->y][snake->x] = SNAKE_HEAD; // set the snake's head
}

void increaseBody(Snake *snake, char key, UserKeybinds userKeys) {
  // add an other body to the snake with the opposite direction of the movement

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
  if (grid[snake.y][snake.x] == APPLE_CELL) {
    return 1; // snake will eat an apple
  }
  return -1; // snake will not eat an apple
}

void printSnakeInfo(Snake snake) {
  printf("\n\n");

  printf("Lenght : %d\n", snake.bodyLength);
  printf("Score : %.2f\n", snake.score);
  printf("[%d] - [%d]\n", snake.x, snake.y);

  /* for (int i = 0; i < snake.bodyLength; i++) {
     printf("[%d][%d] - ", snake.body[i].y, snake.body[i].x);
   }
 */
}