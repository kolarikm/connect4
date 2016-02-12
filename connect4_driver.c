#include <stdio.h>
#include <stdlib.h>
#include "connect4_engine.h"

int size, length_to_win;

int main(int argc, char* *argv) {
  if (argc != 3) {
    printf("Program execution failed!\nReason: Incorrect argument usage. 2 arguments required - board size & win length.\n");
      }
  else {
    size = atoi(argv[1]);
    length_to_win = atoi(argv[2]);
    printf("Game initialized with a board size of %d and a required length of %d to win.\n", size, length_to_win);
  }

  int array[size][size];
  int r, c;
  for (r = 0; r < size; r++) {
    for (c = 0; c < size; c++) {
      array[r][c] = -1;
    }
  }

  place_token(0, 4, size, size, array);
  place_token(0, 4, size, size, array);
  place_token(0, 4, size, size, array);
  place_token(1, 0, size, size, array);
  print_board(size, size, array);
  
  return 0;
}
