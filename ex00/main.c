#include <stdio.h>
#include "ex00/ft_imperative_sudoku.h"
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

  ft_imperative_sudoku(board, matrix);

  show_table(board);
  printf("\n");
  backtrack_please(board, solved_board);
  if (g_solutions == 1)
        show_table(solved_board);
  printf("\nnumber of solutions = %d\n", g_solutions);

  //else


  return(0);
}

// wikipedia sudoku: "........." ".....3.85" "..1.2...." "...5.7..." "..4...1.." ".9......." "5......73" "..2.1...." "....4...9"
// 42 example:  "9...7...." "2...9..53" ".6..124.." "84...1.9." "5.....8.." ".31..4..." "..37..68." ".9..5.741" "47......."
// multiple solution "926571483" "351486279" "874923516" "582367194" "149258367" "7631..825" "2387..651" "617835942" "495612738"
