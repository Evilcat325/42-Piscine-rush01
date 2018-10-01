#include <stdio.h>
//#include "ex00/ft_imperative_sudoku.h"
#define TRUE 1
#define FALSE 0

int g_solutions = 0;
int backtrack_please(int board[9][9], int solved_board[9][9]); //, int matrix[9][9][10])
void    show_table(int board[9][9]);
void create_board(int ac, char **av, int board[9][9]);

int main(int ac, char **av)
{
  int board[9][9];
  int solved_board[9][9];
  int matrix[9][9][10];

  // initialziation
  create_board(ac, av, board);

  //ft_imperative_sudoku(board, matrix);

  show_table(board);
  printf("\n");
  backtrack_please(board, solved_board);
  if (g_solutions == 1)
        show_table(solved_board);
  printf("\nnumber of solutions = %d\n", g_solutions);

  //else


  return(0);
}
