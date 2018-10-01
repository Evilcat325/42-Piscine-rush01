/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imperative_sudoku.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 13:40:44 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 17:13:50 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_imperative_sudoku.h"

void	ft_imperative_sudoku(int board[9][9], int matrix[9][9][10])
{
	int	updated;

	ft_updated_board(board, matrix);
	updated = TRUE;
	while (updated)
	{
		updated = FALSE;
		updated = ft_unique_cell(board, matrix) ? TRUE : updated;
		updated = ft_unique_box(board, matrix) ? TRUE : updated;
		updated = ft_unique_row(board, matrix) ? TRUE : updated;
		updated = ft_unique_col(board, matrix) ? TRUE : updated;
	}
}

int		ft_unique_row(int board[9][9], int matrix[9][9][10])
{
	int number;
	int	row;
	int col;
	int	count;

	number = 0;
	while (++number <= 9)
	{
		row = -1;
		while (++row < 9)
		{
			col = -1;
			count = 0;
			while (++col < 9)
				if (matrix[row][col][number] == POSSIBLE)
					count++;
			col = -1;
			if (count != 1)
				continue;
			while (++col < 9)
			{
				if (matrix[row][col][number] == POSSIBLE)
				{
					board[row][col] = number;
					ft_update(board, matrix, row, col);
					return (TRUE);
				}
			}
		}
	}
	return (FALSE);
}

int		ft_unique_col(int board[9][9], int matrix[9][9][10])
{
	int number;
	int	row;
	int col;
	int	count;

	number = 0;
	while (++number <= 9)
	{
		col = -1;
		while (++col < 9)
		{
			row = -1;
			count = 0;
			while (++row < 9)
				if (matrix[row][col][number] == POSSIBLE)
					count++;
			row = -1;
			if (count != 1)
				continue;
			while (++row < 9)
			{
				if (matrix[row][col][number] == POSSIBLE)
				{
					board[row][col] = number;
					ft_update(board, matrix, row, col);
					return (TRUE);
				}
			}
		}
	}
	return (FALSE);
}

int		ft_unique_box(int board[9][9], int matrix[9][9][10])
{
	int number;
	int	i;
	int j;
	int	count;

	number = 0;
	while (++number <= 9)
	{
		i = -1;
		while (++i < 9)
		{
			j = -1;
			count = 0;
			while (++j < 9)
				if (matrix[BOXR(i, j)][BOXC(i, j)][number] == POSSIBLE)
					count++;
			j = -1;
			if (count != 1)
				continue;
			while (++j < 9)
			{
				if (matrix[BOXR(i, j)][BOXC(i, j)][number] == POSSIBLE)
				{
					board[BOXR(i, j)][BOXC(i, j)] = number;
					ft_update(board, matrix, BOXR(i, j), BOXC(i, j));
					return (TRUE);
				}
			}
		}
	}
	return (FALSE);
}

int		ft_unique_cell(int board[9][9], int matrix[9][9][10])
{
	int i;
	int number;

	i = -1;
	while (++i < 81)
	{
		if (board[i / 9][i % 9] != 0
			|| matrix[i / 9][i % 9][0] + 1 != 9)
			continue;
		number = 0;
		while (++number <= 9)
		{
			if (matrix[i / 9][i % 9][number] != POSSIBLE)
				continue;
			board[i / 9][i % 9] = number;
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

	i = -1;
	number = board[row][col];
	matrix[row][col][0] = 9;
	while (++i < 9)
	{
		matrix[row][col][i + 1] = NOT_POSSIBLE;
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
		if (matrix[ROW(i, row)][COL(i, col)][number] == POSSIBLE)
		{
			matrix[ROW(i, row)][COL(i, col)][number] = NOT_POSSIBLE;
			matrix[ROW(i, row)][COL(i, col)][0]++;
		}
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
