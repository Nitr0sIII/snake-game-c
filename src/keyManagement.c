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
  UserKeybinds newUserKeys;

  printf("Keybinds : \n\n");

  do {
    printf("Binding for Up : ");
    scanf(" %c", &newUserKeys.up);
  } while (acceptedKey(newUserKeys.up) != 1);

  do {
    flush();
    printf("\nBinding for Down : ");
    scanf(" %c", &newUserKeys.down);
  } while (acceptedKey(newUserKeys.down) != 1);

  do {
    flush();
    printf("Binding for Left : ");
    scanf(" %c", &newUserKeys.left);
  } while (acceptedKey(newUserKeys.left) != 1);

  do {
    flush();
    printf("Binding for Right : ");
    scanf(" %c", &newUserKeys.right);
  } while (acceptedKey(newUserKeys.right) != 1);

  return newUserKeys;
}

int acceptedKey(char key) {
  if ((key >= 'A' && key <= 'Z') || (key >= 'a' && key <= 'z')) {
    return 1; // Key accepted
  }

  return -1;
}

void flush() {
  int c;
  do {
    c = getchar();
  } while (c != '\n' && c != EOF);
}