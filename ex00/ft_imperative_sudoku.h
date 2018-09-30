/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imperative_sudoku.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:17:14 by seli              #+#    #+#             */
/*   Updated: 2018/09/29 21:15:56 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMPERATIVE_SUDOKU_H
# define FT_IMPERATIVE_SUDOKU_H
# define POSSIBLE 0
# define NOT_POSSIBLE 1
# define TRUE 1
# define FALSE 0
# define SHOW(X) matrix[row][col][X] == 0 ? X + '0' : ' '

void	ft_updated_board(int board[9][9], int matrix[9][9][10]);
void	ft_update(int board[9][9], int matrix[9][9][10], int row, int col);
int		ft_search_unique_cell(int board[9][9], int matrx[9][9][10]);
void	ft_imperative_sudoku(int board[9][9], int matrix[9][9][10]);

#endif
