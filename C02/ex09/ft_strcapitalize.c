/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 17:35:52 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/19 00:02:31 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

static void	ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] = str[i] + ('a' - 'A');
		i++;
	}
}

static int	ft_is_alnum(char c)
{
	if ((c >= 'a' && c <= 'z')
		|| (c >= 'A' && c <= 'Z')
		|| (c >= '0' && c <= '9'))
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	new_word;
	int	i;

	if (!str)
		return (NULL);
	ft_strlowcase(str);
	new_word = 1;
	i = 0;
	while (str[i])
	{
		if (ft_is_alnum(str[i]))
		{
			if (new_word && (str[i] >= 'a' && str[i] <= 'z'))
				str[i] = str[i] - ('a' - 'A');
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (str);
}
