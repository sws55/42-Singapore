/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:05:46 by sebwong           #+#    #+#             */
/*   Updated: 2023/12/29 15:05:47 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strdup(char *s)
{
	size_t		i;
	size_t		len;
	char		*dup;

    len = 0;
    while (s[len])
        len++;
	dup = (char *)ft_calloc((len + 1), sizeof(char));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

char	*ft_calloc(size_t element, size_t size)
{
	void			*p;
	unsigned char	*pz;
	size_t			b;

	p = malloc(element * size);
	if (p != NULL)
	{
		pz = (unsigned char *)p;
		b = element * size;
		while (b > 0)
		{
			*pz = 0;
			pz++;
			b--;
		}
	}
	return (p);
}

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	size_t	src_len;
	size_t	i;

    src_len = 0;
    while (src[src_len])
        src_len++;
	if (size == 0)
		return (src_len);
	i = 0;
	while (i < size - 1 && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
		{
			return ((char *)&s[i]);
		}
		i++;
	}
	if ((char) c == s[i])
		return ((char *)&s[i]);
	return (NULL);
}

char	*ft_strjoin(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
    // write code that returns the length of s1 for len1 without using strlen()
    len1 = 0;
    while (s1[len1])
        len1++;
	len2 = 0;
    while (s2[len2])
        len2++;
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len1 + len2 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	return (result);
}