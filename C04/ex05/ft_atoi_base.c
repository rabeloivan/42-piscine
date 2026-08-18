/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/28 20:00:47 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:36:54 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

static int	ft_convert_digits(const char *str, const char *base, int base_len)
{
	int	result;
	int	i;

	result = 0;
	while (*str)
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == *str)
			{
				result = result * base_len + i;
				break ;
			}
			i++;
		}
		if (i == base_len)
			break ;
		str++;
	}
	return (result);
}

int	ft_atoi_base(char *str, char *base)
{
	int	result;
	int	base_len;
	int	sign;

	if (!str || !base)
		return (0);
	base_len = ft_validate_base(base);
	if (!base_len)
		return (0);
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = 1;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	result = ft_convert_digits(str, base, base_len);
	return (result * sign);
}
