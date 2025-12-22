#ifndef KEY_MANAGEMENT_H
#define KEY_MANAGEMENT_H

#include <fcntl.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>

void enableTermianlRaw();
void disableTerminalRaw();
int readKey();

#endif