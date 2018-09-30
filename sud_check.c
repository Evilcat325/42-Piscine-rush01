#define TRUE 1
#define FALSE 0

int is_row(int board[9][9], int y, int x, int guess)
{
  int i;

  i = 0;
  if (board[y][x])
    return (FALSE);
  while(i < 9)
  {
    if (board[y][i] == guess)
      return(FALSE);
    i++;
  }
  return(TRUE);
}
int is_column(int board[9][9], int y, int x, int guess)
{
  int i;

  i = 0;
  if (board[y][x])
    return (FALSE);
  while(i < 9)
  {
    if (board[i][x] == guess)
      return(FALSE);
    i++;
  }
  return(TRUE);
}
int is_box(int board[9][9], int y, int x, int guess)
{
  int num[2];

  num[0] = 0;
  if (board[y][x])
    return (FALSE);
  y -= y % 3;
  x -= x % 3;

  while(num[0] < 3)
  {
    num[1] = 0;
    while (num[1] < 3)
    {
      if (board[num[0] + y][num[1] + x] == guess)
        return (FALSE);
      num[1]++;
    }
    num[0]++;
  }
  return (TRUE);
}

int is_valid_and_viable(int board[9][9], int y, int x, int guess, int list[10])
{
    if(is_row(board, y, x, guess) &&
       is_column(board, y, x, guess) &&
       is_box(board, y, x, guess) &&
       list[guess] == 0)
      return (TRUE);
    return (FALSE);
}
