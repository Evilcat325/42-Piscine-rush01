#define TRUE 1
#define FALSE 0

int g_solutions;
int is_valid_and_viable(int board[9][9], int y, int x, int guess); //, int list[10]);
void    show_table(int board[9][9]);

int is_solved(int board[9][9], int *y, int *x)
{
  *y = 0;
  while(*y < 9)
  {
    *x = 0;
    while(*x < 9)
    {
      if (!(board[*y][*x]))
        return (FALSE);
      (*x)++;
    }
    (*y)++;
  }
  return (TRUE);
}

void copy_table(int src_board[9][9], int dest_board[9][9])
{
  int i;
  int j;

  i = 0;
  while (i < 9)
  {
      j = 0;
      while (j < 9)
      {
          dest_board[i][j] = src_board[i][j];
          j++;
      }
      i++;
  }
  g_solutions++;
}


int backtrack_please(int board[9][9], int solved_board[9][9]) //, int matrix[9][9][10])
{
  int x;
  int y;
  int guess;

  if (is_solved(board, &y, &x))
  {
    copy_table(board, solved_board);
    if (g_solutions == 2)
      return (TRUE);
    return(FALSE);
  }

  guess = 1;
  while(guess <= 9)
  {
    if (is_valid_and_viable(board, y, x, guess)) //, matrix[y][x])
    {
      board[y][x] = guess;
      if (backtrack_please(board, solved_board)) //, matrix))
        return (TRUE);
      board[y][x] = 0;
    }
    guess++;
  }
  return (FALSE);
}
