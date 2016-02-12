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

  int col_index = num_columns -1;
  if (column > column_index || column < 0) {
    printf("Invalid column selection. Please enter a number between 0 and %d.", num_columns);
    return 0;
  }
  
}

int winner(int num_rows, int num_columns, int length_to_win, int array[num_rows][num_columns]) {
  return 0;
}

