int guess = 1

int is_solved(int board[9][9], int *y, int *x)
{
  *y = 0;
  while(y < 9)
  {
    *x = 0;
    while(x < 9)
    {
      if (!(board[y][x]))
        return (FALSE);
      (*x)++;
    }
    (*y)++;
  }
  return (TRUE);
}

void backtrack_please(int board[9][9], int matrix[9][9][10])
{
  int x;
  int y;
  int guess;
  int solutions;

  solutions = 0
  if (is_solved(board, &y, &x)
  {
    solutions++;
    return(FALSE);
  }

  guess = 1;
  while(guess <= 9)
  {
    if (is_valid_and_viable(board, y, x, guess, matrix[y][x])
    {
      board[y][x] = guess;
      if(backtrack_please(board, matrix))
        return (TRUE);
      board[y][x] = 0;
    }
    guess++;
  }
  return (FALSE)
}
