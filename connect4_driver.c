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

  place_token(0, 0, size, size, array);
  place_token(0, 1, size, size, array);
  place_token(0, 2, size, size, array);
  place_token(1, 3, size, size, array);
  place_token(1, 4, size, size, array);
  place_token(1, 5, size, size, array);
  place_token(1, 6, size, size, array);
  check_horiz(size, size, length_to_win, array);
  print_board(size, size, array);
  
  return 0;
}

/*
  printf("%c[1;31mHello, world!\n", 27); // green
  31 red
  34 blue
  36 cyan
 */
