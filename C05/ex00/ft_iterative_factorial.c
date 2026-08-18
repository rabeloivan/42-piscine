/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/29 13:52:08 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/16 16:18:48 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	n;

	if (nb < 0)
		return (0);
	if (!nb)
		return (1);
	n = nb - 1;
	while (n > 1)
	{
		nb *= n;
		n--;
	}
	return (nb);
}
