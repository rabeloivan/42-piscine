/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/13 13:33:09 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/19 00:04:11 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_print_hex(unsigned char c)
{
	ft_putchar("0123456789abcdef"[c / 16]);
	ft_putchar("0123456789abcdef"[c % 16]);
}

static void	ft_print_addr(unsigned long addr)
{
	char	buffer[16];
	int		i;

	i = 15;
	while (i >= 0)
	{
		buffer[i] = "0123456789abcdef"[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, buffer, 16);
	write(1, ": ", 2);
}

static void	ft_print_data(const unsigned char *ptr, unsigned int i,
	unsigned int size)
{
	unsigned int	j;

	j = 0;
	while (j < 16)
	{
		if (i + j < size)
			ft_print_hex(ptr[i + j]);
		else
			write(1, "  ", 2);
		if (j % 2 != 0)
			ft_putchar(' ');
		j++;
	}
	j = 0;
	while (j < 16 && i + j < size)
	{
		if (ptr[i + j] >= ' ' && ptr[i + j] <= '~')
			ft_putchar(ptr[i + j]);
		else
			ft_putchar('.');
		j++;
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned char	*ptr;
	unsigned int	i;

	if (!size)
		return (addr);
	if (!addr)
		return (NULL);
	ptr = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_addr((unsigned long)(ptr + i));
		ft_print_data(ptr, i, size);
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
