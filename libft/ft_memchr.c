/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 16:25:14 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 16:25:14 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char *)s;
	while (i < n)
	{
		if (res[i] == (unsigned char)c)
			return ((char *)&res[i]);
		i++;
	}
	return (0);
}
/*
int main()
{
	char s[20] = "Hello Wrodl";
	printf("%s\n", (char *)ft_memchr(s , 'o', 7));
	int tab[7] = {-49, 49, 1, -1, 0, -2, 2};
    printf("%s", (char *)ft_memchr(tab, -1, 7));
}
*/