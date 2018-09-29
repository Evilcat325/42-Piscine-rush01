#include <unistd.h>
#include <stdio.h>

void ft_putchar(char c)
{
  write(1,&c,1);
}

void ft_row(char *argv)
{
    int i = 0;
    int x = 0;
    int n = 1;

    while (argv[i] != '\0')
    {
      x = i;
      if (argv[i] == '.')
      {
        while (n < 10)
        {
          while (x >= 0)
          {
            if (argv[x] != n)
            {
              argv[i] = n - (int)'0';
            }
            x--;
          }
        n++;
        }
      }
    i++;
    }
    printf("%s", argv);
}


int main(int argc, char **argv)
{
  ft_row(argv[1]);
  return(0);
}
