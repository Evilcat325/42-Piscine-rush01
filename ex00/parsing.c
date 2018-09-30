#include <stdio.h>
#include <unistd.h>

void backtrack_please(int board[9][9], int matrix[9][9][10]);

void    als_putchar(char c)
{
    write(1, &c, 1);
}

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
            if (j != 8)
              als_putchar(' ');
            j++;
        }
        als_putchar('\n');
        i++;
    }
}
