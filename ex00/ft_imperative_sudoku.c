/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imperative_sudoku.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:40:44 by seli              #+#    #+#             */
/*   Updated: 2018/09/29 22:05:51 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_imperative_sudoku.h"

void	ft_imperative_sudoku(int board[9][9], int matrix[9][9][10])
{
	int	updated;

	ft_updated_board(board, matrix);
	updated = TRUE;
	while(updated)
	{
		updated = FALSE;
		updated = ft_search_unique_cell(board, matrix);
	}
}

int		ft_search_unique_cell(int board[9][9], int matrix[9][9][10])
{
	int i;
	int number;

	i = -1;
	while (++i < 81)
	{
		if (board[i / 9][i % 9] != 0
			|| matrix[i / 9][ i % 9][0] + 1 != 9)
			continue;
		number = 0;
		while (++number <= 9)
		{
			if (matrix[i / 9][ i % 9][number] != POSSIBLE)
				continue;
			board[i / 9][i % 9] = number;
			//matrix[i / 9][i % 9][0] = 9;
			ft_update(board, matrix, i / 9, i % 9);
			return (TRUE);
		}
	}
	return (FALSE);
}

void	ft_update(int board[9][9], int matrix[9][9][10], int row, int col)
{
	int	i;
	int	number;

	i = 0;
	number = board[row][col];
	while (i < 9)
	{
		if (matrix[row][i][number] == POSSIBLE)
		{
			matrix[row][i][number] = NOT_POSSIBLE;
			matrix[row][i][0]++;
		}
		if (matrix[i][col][number] == POSSIBLE)
		{
			matrix[i][col][number] = NOT_POSSIBLE;
			matrix[i][col][0]++;
		}
		if (matrix[ROW(i)][COL(i)][number] == POSSIBLE)
		{
			matrix[ROW(i)][COL(i)][number] = NOT_POSSIBLE;
			matrix[ROW(i)][COL(i)][0]++;
		}
		i++;
	}
}

void	ft_updated_board(int board[9][9], int matrix[9][9][10])
{
	int	row;
	int	col;

	row = 0;
	while (row < 9)
	{
		col = 0;
		while (col < 9)
		{
			if (board[row][col] != 0)
				ft_update(board, matrix, row, col);
			col++;
		}
		row++;
	}
}
