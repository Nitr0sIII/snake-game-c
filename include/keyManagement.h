#ifndef KEY_MANAGEMENT_H
#define KEY_MANAGEMENT_H

#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

static struct termios orignalTerminal;

typedef struct UserKeybinds {
  char up;
  char down;
  char left;
  char right;
} UserKeybinds;

void enableTerminalRaw();
void disableTerminalRaw();
int readKey();
UserKeybinds setUserKeys();

#endif