/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 14:13:39 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 14:13:40 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*rdest;
	unsigned char	*rsrc;

	i = 0;
	rdest = (unsigned char *)dest;
	rsrc = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	while (i < n)
	{
		rdest[i] = rsrc[i];
		i++;
	}
	return (dest);
}
/*
int main()
{
	char dest[] = "Hello Wrodl";
	char src[] = "Goodbye";
	size_t n = 3;
	ft_memcpy(dest, src, n);
	printf("%s\n", dest);
}*/