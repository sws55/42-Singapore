/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_string.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:22:12 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/29 14:22:13 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ================== ft_putcharwlen & ft_str ==================
// Managing chars and strings
// If there is no string, write "(null)"
// While string has not reached its end, run putchar

#include "ft_printf.h"

void	ft_putcharwlen(char c, int *len)
{
	write(1, &c, 1);
	(*len)++;
}

void	ft_str(char *s, int *len)
{
	int	i;

	i = 0;
	if (!s)
	{
		write(1, "(null)", 6);
		(*len) += 6;
		return ;
	}
	while (s[i] != '\0')
	{
		ft_putcharwlen(s[i], len);
		i++;
	}
}
