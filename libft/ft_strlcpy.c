/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/09 13:23:32 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/09 13:23:33 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (size)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}
/*
int	main(void)
{
    size_t i;
    size_t j;
    char	str2[] = "Hello";
    char	str[] = "Goodbye";
    i = 3;
    j = ft_strlcpy(str2, str, i);
    printf("Here is the expected result: %s\n", str2);
    printf("Num returned: %zu\n", j);
    return (0);
}
*/
