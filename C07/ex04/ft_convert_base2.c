/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/08 18:32:31 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/17 21:46:31 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_convert_digits(const char *nbr, const char *base, int base_len)
{
	int	result;
	int	i;

	result = 0;
	while (*nbr)
	{
		i = 0;
		while (base[i])
		{
			if (base[i] == *nbr)
			{
				result = result * base_len + i;
				break ;
			}
			i++;
		}
		if (i == base_len)
			break ;
		nbr++;
	}
	return (result);
}

int	ft_atoi_base(const char *nbr, const char *base, int base_len)
{
	int	result;
	int	sign;

	while (*nbr == ' ' || (*nbr >= '\t' && *nbr <= '\r'))
		nbr++;
	sign = 1;
	while (*nbr == '+' || *nbr == '-')
	{
		if (*nbr == '-')
			sign *= -1;
		nbr++;
	}
	result = ft_convert_digits(nbr, base, base_len);
	return (result * sign);
}
