/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 15:20:56 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 15:20:57 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*d;
	unsigned char	*s;	

	d = dest;
	s = (unsigned char *)src;
	if (dest < src)
		return (ft_memcpy(dest, src, n));
	if (dest > src)
	{
		while (n--)
			d[n] = s[n];
	}
	return (dest);
}
/*
int main()
{
	char dest[] = "Hello Wrold";
	char src[] = "Goodbey";
	size_t n = 3;
	ft_memmove(dest, src, n);
	printf("%s\n", dest);
}
*/