/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: irabelo <irabelo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/23 18:23:07 by irabelo           #+#    #+#             */
/*   Updated: 2026/08/17 18:41:12 by irabelo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static unsigned int	ft_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_len;
	unsigned int	src_len;
	unsigned int	total_len;
	unsigned int	i;

	dest_len = 0;
	while (dest_len < size && dest[dest_len])
		dest_len++;
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (size + src_len);
	total_len = dest_len + src_len;
	i = 0;
	while (dest_len < size - 1 && src[i])
		dest[dest_len++] = src[i++];
	dest[dest_len] = '\0';
	return (total_len);
}
