/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:47:38 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 17:27:10 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	ft_print_square(int x, int y, int row, int column)
{
	if ((row == 1 || row == y) && (column == 1 || column == x))
		ft_putchar('o');
	else if ((row != 1 && column == 1) || (row != y && column == x))
		ft_putchar('|');
	else if (row == 1 || row == y)
		ft_putchar('-');
	else if (row != 1 || row != y)
		ft_putchar(' ');
}

void	rush(int x, int y)
{
	int	row;
	int	column;

	if (x <= 0 || y <= 0 || x == 2147483647 || y == 2147483647)
	{
		write(2, "Error\n", 6);
		return ;
	}
	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			ft_print_square(x, y, row, column);
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}
