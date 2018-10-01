/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imperative_sudoku.h                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seli <seli@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/29 20:17:14 by seli              #+#    #+#             */
/*   Updated: 2018/09/30 20:20:06 by seli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_IMPERATIVE_SUDOKU_H
# define FT_IMPERATIVE_SUDOKU_H
# define POSSIBLE 0
# define NOT_POSSIBLE 1
# define TRUE 1
# define FALSE 0
# define SHOW(X) matrix[row][col][X] == 0 ? X + '0' : ' '
# define ROW(X, Y) ((Y / 3) * 3 + X / 3)
# define COL(X, Y) ((Y / 3) * 3 + X % 3)
# define BOXR(X, Y) ((X / 3) * 3 + Y / 3)
# define BOXC(X, Y) ((X % 3) * 3 + Y % 3)

void	ft_updated_board(int board[9][9], int matrix[9][9][10]);
void	ft_update(int board[9][9], int matrix[9][9][10], int row, int col);
void	ft_cell(int b[9][9], int m[9][9][10], int *updated);
void	ft_row(int b[9][9], int m[9][9][10], int number, int *updated);
void	ft_col(int b[9][9], int m[9][9][10], int number, int *updated);
void	ft_box(int b[9][9], int m[9][9][10], int number, int *updated);
void	ft_imperative_sudoku(int board[9][9], int matrix[9][9][10]);
int		is_row_valid(int board[9][9], int row, int col, int guess);
int		is_column_valid(int board[9][9], int row, int col, int guess);
int		is_box_valid(int board[9][9], int row, int col, int guess);
int		is_guess_valid(int b[9][9], int row, int col, int guess);

#endif
