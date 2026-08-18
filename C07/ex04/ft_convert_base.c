/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 17:51:41 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:28:06 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_atoi_base(const char *nbr, const char *base, int base_len);

static int	ft_validate_base(const char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-'
			|| base[i] <= ' ' || base[i] > '~')
			return (0);
		j = i + 1;
		while (base[j])
		{
			if (base[j] == base[i])
				return (0);
			j++;
		}
		i++;
	}
	if (i < 2)
		return (0);
	return (i);
}

static int	ft_get_alloc_len(int num, int base_len)
{
	int		total_len;
	long	n;

	total_len = 0;
	n = num;
	if (n <= 0)
	{
		n = -n;
		total_len++;
	}
	while (n > 0)
	{
		n /= base_len;
		total_len++;
	}
	return (total_len);
}

static char	*ft_build_result(int num, int total_len,
	const char *base_to, int base_to_len)
{
	char	*result;
	long	n;

	result = malloc(total_len + 1);
	if (!result)
		return (NULL);
	result[total_len] = '\0';
	n = num;
	if (n < 0)
		n = -n;
	total_len--;
	while (total_len >= 0)
	{
		result[total_len] = base_to[n % base_to_len];
		n /= base_to_len;
		if (total_len == 0 && num < 0)
			result[0] = '-';
		total_len--;
	}
	return (result);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	char	*result;
	int		base_from_len;
	int		base_to_len;
	int		num;
	int		total_len;

	if (!nbr || !base_from || !base_to)
		return (NULL);
	base_from_len = ft_validate_base(base_from);
	base_to_len = ft_validate_base(base_to);
	if (!base_from_len || !base_to_len)
		return (NULL);
	num = ft_atoi_base(nbr, base_from, base_from_len);
	total_len = ft_get_alloc_len(num, base_to_len);
	result = ft_build_result(num, total_len, base_to, base_to_len);
	return (result);
}
