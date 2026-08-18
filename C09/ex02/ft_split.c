/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/10 11:16:04 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/18 23:10:31 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	ft_is_sep(const char *charset, char c)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_words(const char *str, const char *charset)
{
	int	new_word;
	int	word_count;
	int	i;

	new_word = 1;
	word_count = 0;
	i = 0;
	while (str[i])
	{
		if (!ft_is_sep(charset, str[i]))
		{
			if (new_word)
				word_count++;
			new_word = 0;
		}
		else
			new_word = 1;
		i++;
	}
	return (word_count);
}

static char	*ft_dup_word(const char *str, const char *charset)
{
	char	*word;
	int		len;
	int		i;

	len = 0;
	while (str[len] && !ft_is_sep(charset, str[len]))
		len++;
	word = malloc(len + 1);
	if (!word)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**array;
	int		n_words;
	int		i;

	if (!str || !charset)
		return (NULL);
	n_words = ft_count_words(str, charset);
	array = malloc(sizeof(char *) * (n_words + 1));
	if (!array)
		return (NULL);
	array[n_words] = NULL;
	i = 0;
	while (i < n_words)
	{
		while (*str && ft_is_sep(charset, *str))
			str++;
		array[i] = ft_dup_word(str, charset);
		if (!array[i])
			return (NULL);
		while (*str && !ft_is_sep(charset, *str))
			str++;
		i++;
	}
	return (array);
}
