#include "../headers/loader.h"
#include <stdio.h>
#include <unistd.h>
#define LIB_PATH "./lib/mylib.so"
unsigned int sToMs(unsigned int seconds) {
    return seconds * 1000;
}
int main() {
  int run = 1;
  char c=0;
  while (run != 0) {
    if ((c=getchar())!='\n') {
      if (c == 'r') {
        open_and_call(LIB_PATH, "my_func");
      }
      if (c == 'e') {
        break;
      }
    }
  }
}
