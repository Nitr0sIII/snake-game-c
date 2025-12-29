#include "../include/snakeManagement.h"
#include <stdio.h>

Snake initSnake(char *path) {

  Snake newSnake;
  newSnake.x = 5;
  newSnake.y = 5;
  newSnake.bodyLength = 0;
  newSnake.score = 0.0f;
  newSnake.hit = NO_HIT;

  FILE *file = fopen(path, "rb");

  if (file == NULL) {
    newSnake.bestScore = 0.0f;
  } else {
    Snake saveSnake;
    fread(&saveSnake, sizeof(Snake), 1, file);
    newSnake.bestScore = saveSnake.bestScore;
    fclose(file);
  }

  return newSnake;
}

void updateBestScore(Snake *snake) {
  if (snake->score > snake->bestScore) {
    snake->bestScore = snake->score;
  }
}

void printSnakeInfo(Snake snake) {
  printf("\n\n");

  printf(CYN "╔════════════════════════════════╗\n" RESET);
  printf(CYN "║" RESET GRN "    🐍 SNAKE GAME STATISTICS    " RESET CYN
             "║\n" RESET);
  printf(CYN "╠════════════════════════════════╣\n" RESET);
  printf(CYN "║" RESET YEL " 📏 Length   : " WHT "%-14d" RESET CYN
             "   ║\n" RESET,
         snake.bodyLength);
  printf(CYN "║" RESET YEL " 🏆 Score    : " WHT "%-14.1f" RESET CYN
             "   ║\n" RESET,
         snake.score);
  printf(CYN "║" RESET YEL " 📍 Position : " WHT "X:%-3d Y:%-5d" RESET CYN
             "    ║\n" RESET,
         snake.x, snake.y);
  printf(CYN "║" RESET MAG " ⭐ Best     : " WHT "%-14.1f" RESET CYN
             "   ║\n" RESET,
         snake.bestScore);
  printf(CYN "╚════════════════════════════════╝" RESET);

  /* for (int i = 0; i < snake.bodyLength; i++) {
     printf("[%d][%d] - ", snake.body[i].y, snake.body[i].x);
   }
 */
}