#include <stdio.h>
#include <stdlib.h>
#include "connect4_engine.h"

// The array is passed as a reference in C so it can be modified in every function

// -2 is for a tie
// -1 is for no winner yet
// 0 is player 1
// 1 is player 2

/*

For checking horizontal :: if num_columns - column played < length to win return false
			|| if column played - length to win < 0 return false

For checking vertical  :: same idea as above

*/

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {

  //Must modify the board
  //Check from bottom of col and move up to look for an empty space

  //Check that the desired column is within bounds
  if (column > (num_columns-1) || column < 0) {
    printf("Invalid column selection. Please enter a number between 0 and %d.\n", num_columns);
    return 0;
  }

  //Starting at bottom row, search upward looking for open spot to place player token
  for (int i = (num_rows-1); i >=0; i--) {
    if (board[i][column] == -1) {
      board[i][column] = player;
      return 1;
    }
  }
  //Token failed to be placed
  return 0;
}

int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
  // -2 is for a tie
  // -1 is for no winner yet
  // 0 is player 1
  // 1 is player 2
  // Check horizontal, vertical, diagonal

   return 0;
}

int check_horiz(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {

}

void print_board(int num_rows, int num_columns, int board[num_rows][num_columns]) {
  char print_board[num_rows][num_columns];
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_columns; j++) {
      if (board[i][j] == -1)
	print_board[i][j] = '.';
      if (board[i][j] == 0)
	print_board[i][j] = '0';
      if (board[i][j] == 1)
	print_board[i][j] = '1';
    }
  }
  for (int i = 0; i < num_rows; i++) {
    for (int j = 0; j < num_columns; j++) {
      printf(" %c ", print_board[i][j]);
    }
    printf("\n");
  }
}
