/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 10:51:48 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/19 00:00:35 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr_non_printable(char *str)
{
	unsigned char	str_value;
	int				i;

	if (!str)
		return ;
	i = 0;
	while (str[i])
	{
		str_value = str[i];
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_putchar('\\');
			ft_putchar("0123456789abcdef"[str_value / 16]);
			ft_putchar("0123456789abcdef"[str_value % 16]);
		}
		else
			ft_putchar(str[i]);
		i++;
	}
}
