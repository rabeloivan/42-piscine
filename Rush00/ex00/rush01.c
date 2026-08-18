/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/17 20:47:40 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 17:28:11 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

static void	ft_special_cases(int x, int y)
{
	int	row;
	int	column;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			if (row == 1 && column == 1)
				ft_putchar('/');
			else if ((row == y && column == 1) || (row == 1 && column == x))
				ft_putchar('\\');
			else if ((row != 1 && column == 1)
				|| (row != y && column == x)
				|| (row == 1 || row == y))
				ft_putchar('*');
			else if (row != 1 || row != y)
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}

static void	ft_print_square(int x, int y)
{
	int	row;
	int	column;

	row = 1;
	while (row <= y)
	{
		column = 1;
		while (column <= x)
		{
			if ((row == 1 && column == 1) || (row == y && column == x))
				ft_putchar('/');
			else if ((row == 1 && column == x) || (row == y && column == 1))
				ft_putchar('\\');
			else if ((row != 1 && column == 1)
				|| (row != y && column == x)
				|| (row == 1 || row == y))
				ft_putchar('*');
			else if (row != 1 || row != y)
				ft_putchar(' ');
			column++;
		}
		ft_putchar('\n');
		row++;
	}
}

void	rush(int x, int y)
{
	if (x <= 0 || y <= 0 || x == 2147483647 || y == 2147483647)
	{
		write(2, "Error\n", 6);
		return ;
	}
	if (x == 1 || y == 1)
		ft_special_cases(x, y);
	else
		ft_print_square(x, y);
}
