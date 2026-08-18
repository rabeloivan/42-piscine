/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 17:32:57 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:28:00 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static long	ft_abs(long n)
{
	if (n < 0)
		return (-n);
	return (n);
}

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;

	if (!range)
		return (0);
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	size = ft_abs((long)max - (long)min);
	*range = malloc(sizeof(int) * size);
	if (!*range)
		return (-1);
	i = 0;
	while (i < size)
		(*range)[i++] = min++;
	return (size);
}
