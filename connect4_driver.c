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
  
  //Set up loop that only exits after winner or tie

  int play = 1;
  int player = 0;
  int col;
  while (play) {
    
    printf("Player %d, please choose a column:\n", player+1);
    scanf("%d", &col);
    int place = place_token(player, col-1, size, size, array);
    if (place == 0)
      continue;
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
