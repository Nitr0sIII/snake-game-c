#include "../include/keyManagement.h"

int main() {
  enableTermianlRaw();

  // first test

  while (1) {
    int key = readKey();

    if (key != -1) {
      if (key == 'q')
        break;

      printf("Key: %c\n", key);
    }

    usleep(50000); // 50 ms
  }

  disableTerminalRaw();
  return 0;
}
