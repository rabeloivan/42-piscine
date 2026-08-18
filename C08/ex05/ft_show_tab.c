/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/09 12:37:19 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:19:20 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

static unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb + '0');
}

void	ft_show_tab(t_stock_str *par)
{
	int	i;

	if (!par)
		return ;
	i = 0;
	while (par[i].str)
	{
		write(1, par[i].str, ft_strlen(par[i].str));
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		write(1, par[i].copy, ft_strlen(par[i].copy));
		ft_putchar('\n');
		i++;
	}
}
