#include "../include/movementManagement.h"

void moveSnake(char **grid, Snake *snake, int gridSize, char key,
               UserKeybinds userKeys) {
  grid[snake->y][snake->x] = ' ';

  if (key == userKeys.up && snake->y > 0)
    snake->y--;
  else if (key == userKeys.down && snake->y < gridSize - 1)
    snake->y++;
  else if (key == userKeys.left && snake->x > 0)
    snake->x--;
  else if (key == userKeys.right && snake->x < gridSize - 1)
    snake->x++;

  grid[snake->y][snake->x] = 'o';
}

int snakeReachedBorder(Snake snake, int gridSize) {
  if (snake.x == 0 || snake.x == gridSize - 2 || snake.y == 0 ||
      snake.y == gridSize - 2) {
    return 1; // border reached
  }

  return -1; // border not reached
}