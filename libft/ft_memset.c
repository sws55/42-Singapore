/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 10:35:18 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 10:35:20 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (i < n)
	{
		res[i] = (char)c;
		i++;
	}
	return (res);
}
/*
int main()
{
	char s[] = "Hello World!";
	int c = 'e';
	size_t n = 20;

	ft_memset(s, c, n);
	printf("%s\n", s);
}
*/