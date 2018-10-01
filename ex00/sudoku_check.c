/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku_check.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lisimpki <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 16:24:46 by lisimpki          #+#    #+#             */
/*   Updated: 2018/09/30 16:50:27 by lisimpki         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define TRUE 1
#define FALSE 0

int		is_row(int board[9][9], int y, int x, int guess)
{
	int i;

	i = 0;
	if (board[y][x])
		return (FALSE);
	while (i < 9)
	{
		if (board[y][i] == guess)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		is_column(int board[9][9], int y, int x, int guess)
{
	int i;

	i = 0;
	if (board[y][x])
		return (FALSE);
	while (i < 9)
	{
		if (board[i][x] == guess)
			return (FALSE);
		i++;
	}
	return (TRUE);
}

int		is_box(int board[9][9], int y, int x, int guess)
{
	int num[2];

	num[0] = 0;
	if (board[y][x])
		return (FALSE);
	y -= y % 3;
	x -= x % 3;
	while (num[0] < 3)
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

int		valid_and_viable(int b[9][9], int y, int x, int guess, int list[10])
{
	if( //(list[guess] == 0 &&
	is_row(b, y, x, guess) &&
	is_column(b, y, x, guess) &&
	is_box(b, y, x, guess))
		return (TRUE);
	return (FALSE);
}
