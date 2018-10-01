/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtrack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:21:44 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 21:14:14 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_imperative_sudoku.h"

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

void	copy_table(int src[9][9], int dst[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			dst[i][j] = src[i][j];
			j++;
		}
		i++;
	}
}

int		backtrack(int b[9][9], int s[9][9], int m[9][9][10], int *solution)
{
	int i;
	int guess;

	i = next_empty_cell(b);
	if (i == SOLVED)
	{
		copy_table(b, s);
		if ((*solution)++ == 1)
			return (STOP);
		return (NEXT);
	}
	guess = 0;
	while (++guess <= 9)
	{
		if (m[i / 9][i % 9][guess] == NOT_POSSIBLE)
			continue;
		if (is_guess_valid(b, i / 9, i % 9, guess))
		{
			b[i / 9][i % 9] = guess;
			if (backtrack(b, s, m, solution) == STOP)
				return (STOP);
			b[i / 9][i % 9] = 0;
		}
	}
	return (NEXT);
}
