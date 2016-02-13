#include <stdio.h>
#include <stdlib.h>
#include "connect4_engine.h"

// The array is passed as a reference in C so it can be modified in every function

int place_token(int player, int column, int num_rows, int num_columns, int board[num_rows][num_columns]) {

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
  for (int r = 0; r < num_rows; r++) {
    for (int c = 0; c <= (num_columns - length_to_win); c++) {
      int match = 0;
      if (board[r][c] != -1) {
	for (int x = 0; x < length_to_win; x++) {
	  if (board[r][c+x] == board[r][c]) {
	    match++;
	  }
	}
	if (match == length_to_win) {
	  printf("Player %d wins.\n", board[r][c]);
	  return board[r][c];
	}
      }
    }
  }
  //No winner yet
  return -1;
}

int check_vert(int num_rows, int num_columns, int length_to_win, int board[num_rows][num_columns]) {
  for (int r = (num_rows - 1); r >= (length_to_win-1); r--) {
    for (int c = 0; c < num_columns; c++) {
      int match = 0;
      if (board[r][c] != -1) {
	for (int x = 0; x < length_to_win; x++) {
	  if (board[r-x][c] == board[r][c]) {
	    match++;
	  }
	}
	if (match == length_to_win) {
	  printf("Player %d wins.\n", board[r][c]);
	  return board[r][c];
	}
      }
    }
  }
  return -1;
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
