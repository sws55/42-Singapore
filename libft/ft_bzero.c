/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 11:20:28 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 11:20:29 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*res;

	i = 0;
	res = (char *)s;
	while (i < n)
	{
		res[i] = '\0';
		i++;
	}
}
/*
int main()
{
	int i = 0;

	char s[] = "Hello World";
	size_t n = 8;
	printf("%s\n", s);
	ft_bzero(s, n);
	printf("%s\n", s);
}*/