/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 14:56:41 by sebwong           #+#    #+#             */
/*   Updated: 2023/08/25 15:15:38 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_toupper(int c)
{
	if (97 <= c && c <= 122)
		c = c - 32;
	return (c);
}
/*
int main()
{
	int c = 'h';
	printf("%c\n", ft_toupper(c));
}
*/