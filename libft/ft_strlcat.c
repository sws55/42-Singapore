/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 10:58:16 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/13 16:29:42 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	dlen;
	size_t	slen;

	dlen = 0;
	slen = ft_strlen(src);
	while (*dst && size > 0)
	{
		dst++;
		dlen++;
		size--;
	}
	while (*src && size > 1)
	{
		*dst++ = *src++;
		size--;
	}
	if (size == 1 || *src == 0)
		*dst = '\0';
	return (slen + dlen);
}

/*
int main()
{
	char dst[] = "Hello ";
	char src[] = "World!";
	printf("%s\n", ft_strlcat(dst, src, 3));
}
*/
