#include <stdio.h>
#include <stdlib.h>
#include "connect4_engine.h"

int main(int argc, char* *argv) {
  if (argc != 3) {
    printf("Program execution failed!\nReason: Incorrect argument usage. 2 arguments required - board size & win length.\n");
      }
  else {
    int size = atoi(argv[1]);
    int length_to_win = atoi(argv[2]);
    printf("Game initialized with a board size of %d and a required length of %d to win.\n", size, length_to_win);
  }
  
  return 0;
}
