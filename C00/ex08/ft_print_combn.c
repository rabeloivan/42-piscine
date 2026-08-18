/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:14:52 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 17:50:27 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_combination(int *digits, int n)
{
	int	i;

	i = 0;
	while (i < n)
		ft_putchar(digits[i++] + '0');
}

static void	ft_update_combination(int *digits, int n)
{
	int	i;

	i = n - 1;
	while (digits[i] == 10 - n + i)
		i--;
	digits[i]++;
	i++;
	while (i < n)
	{
		digits[i] = digits[i - 1] + 1;
		i++;
	}
}

void	ft_print_combn(int n)
{
	int	digits[10];
	int	i;

	if (n < 1 || n > 9)
		return ;
	i = 0;
	while (i < n)
	{
		digits[i] = i;
		i++;
	}
	while (digits[0] != 10 - n)
	{
		i = 0;
		ft_print_combination(digits, n);
		write(1, ", ", 2);
		ft_update_combination(digits, n);
	}
	ft_print_combination(digits, n);
}
