#include <stdio.h>
#include <unistd.h>

void create_board(int ac, char **av, int board[9][9])
{
  int i;
  int j;

 j = 1;
  while (j < ac)
  {
    i = 0;
    while (i < 9)
    {
      if (av[j][i] == '.')
        board[j - 1][i] = 0;
      else
        board[j - 1][i] = av[j][i] - '0';
      i++;
    }
    j++;
  }
}



void    als_putchar(char c)
{
    write(1, &c, 1);
}

void    do_nothing(void)
{}

void    show_table(int board[9][9])
{
    int i;
    int j;

    i = 0;
    while (i < 9)
    {
        j = 0;
        while (j < 9)
        {
            als_putchar(board[i][j] + '0');
            if (j == 8)
              do_nothing();
            else
              als_putchar(' ');
            j++;
        }
        als_putchar('\n');
        i++;
    }
}


int main(int ac, char **av)
{
  /*char *av[] = {
  **  "sudoku",
  **  "9...7....",
  **  "2...9..53",
  **  ".6..124..",
  **  "84...1.9.",
  **  "5.....8..",
  **  ".31..4...",
  **  "..37..68.",
  **  ".9..5.741",
  **  "47.......",
  **};
  */

  //int ac = 10;

  int board[9][9];
  create_board(ac, av, board);
  show_table(board);

  return(0);
}
