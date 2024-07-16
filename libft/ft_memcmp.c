/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/08 21:19:01 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/08 21:19:02 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	unsigned char		*rs1;
	unsigned char		*rs2;

	i = 0;
	rs1 = (unsigned char *)s1;
	rs2 = (unsigned char *)s2;
	while (i < n)
	{
		if (rs1[i] != rs2[i])
		{
			if (rs1[i] > rs2[i])
				return (1);
			return (-1);
		}
		i++;
	}
	return (0);
}
/*
int main()
{
	char s1[] = "t\200";
	char s2[] = "t\0";
	size_t n = 2;
	printf("%d\n", ft_memcmp(s1, s2, n));
	printf("%c\n", s1[1]);
	printf("%c\n", s2[1]);
}
*/