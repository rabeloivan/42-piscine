/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/01 16:12:33 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 22:29:41 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	main(int argc, char **argv)
{
	int	i;

	if (argc > 1)
	{
		i = argc - 1;
		while (i >= 1)
		{
			write(1, argv[i], ft_strlen(argv[i]));
			write(1, "\n", 1);
			i--;
		}
	}
	return (0);
}
