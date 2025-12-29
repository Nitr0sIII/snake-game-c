#include "../include/loseMenu.h"

void displayLoseMenu(Snake snake) {
  printf("\033[2J\033[H");

  printSnakeInfo(snake);

  printf("\n\n");
  printf(CYN "╔═════════════════════════════════╗\n" RESET);
  printf(CYN "║" RESET RED "          💥 GAME OVER !         " RESET CYN
             "║\n" RESET);
  printf(CYN "╚═════════════════════════════════╝\n" RESET);

  printf("\n");
}