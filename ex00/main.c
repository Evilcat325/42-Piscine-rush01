/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/30 20:41:02 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 21:20:09 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "ft_imperative_sudoku.h"

int		main(int ac, char **av)
{
	int	solutions = 0;
	int	board[9][9] = {{0}};
	int	solved_board[9][9]= {{0}};
	int	matrix[9][9][10] = {{{0}}};

	create_board(ac, av, board);
	print_board(board);
	printf("\n");
	ft_imperative_sudoku(board, matrix);
	print_board(board);
	printf("\n");
	backtrack(board, solved_board, matrix, &solutions);
	if (solutions == 1)
		print_board(solved_board);
	else
		write(1, "Error\n", 6);
	return (0);
}
