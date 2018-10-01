/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:03:46 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 20:04:23 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	create_board(int ac, char **av, int board[9][9])
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

void	print_board(int board[9][9])
{
	int i;
	int j;

	i = 0;
	while (i < 9)
	{
		j = 0;
		while (j < 9)
		{
			ft_putchar(board[i][j] + '0');
			if (j < 8)
				ft_putchar(' ');
			j++;
		}
		ft_putchar('\n');
		i++;
	}
}
