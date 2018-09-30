#include <stdio.h>
#define TRUE 1
#define FALSE 0

int is_valid(int board[9][9], int y, int x, int guess);

int main(int ac, char **av)
{
int board[9][9] = {
  {1,2,3,0,0,0,0,0,0},
  {4,5,6,0,0,0,0,0,0},
  {7,8,0,0,0,0,0,0,0},
  {0,0,0,1,2,3,0,0,0},
  {0,0,0,4,0,6,0,0,0},
  {0,0,0,7,8,9,0,0,0},
  {0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0,0},
};

int y;
int x;
int guess;
int n;

y = 4;
x = 4;
guess = 5;

printf("matrix value = %d\n", board[y][x]);
printf("guess value = %d\n", guess);

if (is_valid(board, y, x, guess))
  puts("SUCCESS");
else
  puts("FAILURE");

return (0);
n = is_valid(board, y, x, guess);

//printf('%d', n);

//______________ print matrix_____________

  for (int i = 0; i< 9 ; i++)
  {
    for (int j = 0; j < 9; j++)
    {
      printf("%d ",board[i][j]);
      printf("\n");
    }
  }
  return 0;
}
