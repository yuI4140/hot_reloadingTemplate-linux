#include "../headers/loader.h"
#include <stdio.h>
#define LIB_PATH "./lib/mylib.so"
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
