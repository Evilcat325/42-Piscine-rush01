/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:19:00 by seli              #+#    #+#             */
/*   Updated: 2018/09/29 21:24:33 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_imperative_sudoku.h"

void	ft_print_soduku(int board[9][9])
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			printf("%d ", board[row][col]);
			col++;
		}
		printf("\n");
		row++;
	}
}

void	ft_print_matrix(int matrix[9][9][10])
{
	int row;
	int col;

	row = 0;
	while (row < 9)
	{
    col = 0;
    while (col < 9)
    {
      printf("%c %c %c |", SHOW(1), SHOW(2), SHOW(3));
      col ++;
    }
    printf("\n");
    col = 0;
    while (col < 9)
    {
      printf("%c %c %c |", SHOW(4), SHOW(5), SHOW(6));
      col ++;
    }
    printf("\n");
    col = 0;
    while (col < 9)
    {
      printf("%c %c %c |", SHOW(7), SHOW(8), SHOW(9));
      col ++;
    }
    printf("\n");
		printf("------------------------------------------------------------\n");
		row++;
	}
}

int main(void) {
  int board[9][9] = {
    {5, 3, 0, 0, 7, 0, 0, 0, 0},
    {6, 0, 0, 1, 9, 5, 0, 0, 0},
    {0, 9, 8, 0, 0, 0, 0, 6, 0},
    {8, 0, 0, 0, 6, 0, 0, 0, 3},
    {4, 0, 0, 8, 0, 3, 0, 0, 1},
    {7, 0, 0, 0, 2, 0, 0, 0, 6},
    {0, 6, 0, 0, 0, 0, 2, 8, 0},
    {0, 0, 0, 4, 1, 9, 0, 0, 5},
    {0, 0, 0, 0, 8, 0, 0, 7, 9},
  };
  int matrix[9][9][10] = {{{0}}};

  ft_print_soduku(board);
  printf("------------------\n");
  ft_imperative_sudoku(board, matrix);
  ft_print_soduku(board);
  printf("------------------\n");
  ft_print_matrix(matrix);
  return 0;
}
