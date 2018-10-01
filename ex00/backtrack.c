/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:21:44 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 20:38:33 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_imperative_sudoku.h"

int		g_solutions = 0;

int		next_empty_cell(int board[9][9])
{
	int	i;

	i = 0;
	while (i < 81)
	{
		if (board[i / 9][i % 9] == 0)
			return (i);
		i++;
	}
	return (SOLVED);
}

void	copy_table(int src_board[9][9], int dest_board[9][9])
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
}

int		backtrack_please(int b[9][9], int s[9][9], int m[9][9][10])
{
	int col;
	int row;
	int guess;

	if (next_empty_cell(b) == SOLVED)
	{
		copy_table(b, s);
		if (++g_solutions == 2)
			return (STOP);
		return (NEXT);
	}
	guess = 0;
	while (++guess <= 9)
	{
		if (m[row][col][guess] == NOT_POSSIBLE)
			continue;
		if (is_guess_valid(b, row, col, guess))
		{
			b[row][col] = guess;
			if (backtrack_please(b, s, m) == STOP)
				return (STOP);
			b[row][col] = 0;
		}
	}
	return (NEXT);
}
