/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 14:15:08 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:26:04 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	ft_is_square_safe(const char *board, int column, char row)
{
	int	i;

	i = 0;
	while (i < column)
	{
		if (board[i] == row
			|| board[i] - i == row - column
			|| board[i] + i == row + column)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_solve(char *board, int column)
{
	int		count;
	char	row;

	if (column == 10)
	{
		write(1, board, 11);
		return (1);
	}
	count = 0;
	row = '0';
	while (row <= '9')
	{
		if (ft_is_square_safe(board, column, row))
		{
			board[column] = row;
			count += ft_solve(board, column + 1);
		}
		row++;
	}
	return (count);
}

int	ft_ten_queens_puzzle(void)
{
	char	board[11];

	board[10] = '\n';
	return (ft_solve(board, 0));
}
