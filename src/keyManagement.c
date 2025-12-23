#include "../include/keyManagement.h"

void enableTerminalRaw() {
  struct termios newTerminal;

  tcgetattr(STDIN_FILENO, &orignalTerminal); // get parameters of the terminal

  newTerminal = orignalTerminal; // into "orginalTerminal"

  newTerminal.c_lflag &= ~(ICANON | ECHO);        // set newTerminal in raw mode
  tcsetattr(STDIN_FILENO, TCSANOW, &newTerminal); // apply configuration

  fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK); // set stdin : non-blocking
}

void disableTerminalRaw() {
  tcsetattr(STDIN_FILENO, TCSANOW,
            &orignalTerminal); // apply configuration of the orignalTerminal
}

int readKey() {
  char c;
  if (read(STDIN_FILENO, &c, 1) == 1)
    return c;
  return -1;
}

UserKeybinds setUserKeys() {
  // mettre des vérificaitons des scanfs
  UserKeybinds newUserKeys;

  printf("Keybinds : \n\n");

  printf("UP : ");
  scanf(" %c", &newUserKeys.up);

  printf("DOWN : ");
  scanf(" %c", &newUserKeys.down);

  printf("LEFT : ");
  scanf(" %c", &newUserKeys.left);

  printf("RIGHT : ");
  scanf(" %c", &newUserKeys.right);

  return newUserKeys;
}