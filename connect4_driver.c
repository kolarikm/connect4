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
  /*
  place_token(0, 0, size, size, array);
  place_token(0, 1, size, size, array);
  place_token(0, 1, size, size, array);
  place_token(0, 2, size, size, array);
  place_token(0, 2, size, size, array);
  place_token(0, 2, size, size, array);
  place_token(0, 3, size, size, array);
  place_token(0, 3, size, size, array);
  place_token(0, 3, size, size, array);
  place_token(0, 3, size, size, array);
  place_token(0, 1, size, size, array);
  place_token(0, 2, size, size, array);
  place_token(1, 3, size, size, array);
  place_token(1, 4, size, size, array);
  place_token(1, 5, size, size, array);
  
  array[0][0] = 0;
  array[1][1] = 0;
  array[2][2] = 0;
  array[3][3] = 0;
 
  array[3][6] = 1;
  array[2][7] = 1;
  array[1][8] = 1;
  array[0][9] = 1;
  

  array[1][1] = 0;
  array[9][7] = 1;
  array[8][6] = 1;
  array[7][5] = 1;
  array[6][4] = 1;
  check_horiz(size, size, length_to_win, array);
  check_vert(size, size, length_to_win, array);
  check_f_diag(size, size, length_to_win, array);
  check_b_diag(size, size, length_to_win, array);
  print_board(size, size, array);
  */
  
  //Set up loop that only exits after winner or tie

  int play = 1;
  int player = 0;
  int col;
  while (play) {
    
    printf("Player %d, please choose a column:\n", player+1);
    scanf("%d", &col);
    place_token(player, col-1, size, size, array);
    print_board(size, size, array);
    int win = winner(size, size, length_to_win, array);
    if (win == 0 || win == 1) {
      printf("Player %d wins!\n", win+1);
      play = 0;
    }
    if (win == -2) {
      printf("Game ends in a tie!\n");
      play = 0;
    }
      player = !player;
  }
  
  return 0;
}

/*
  printf("%c[1;31mHello, world!\n", 27); // green
  31 red
  34 blue
  36 cyan
 */
