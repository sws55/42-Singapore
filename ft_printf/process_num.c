/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_num.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 14:21:53 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/29 14:21:55 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// ================== ft_number ==================
// Checks if num == min int value (MIV), and write the same number
// If the number is -ve, put '-',
// Then if the number != MIV, recursively negate the -ve sign for all nums
// Process the numbers and keep on putchar until the last digit

// ================== ft_pointer ==================
// Checks if memory address is empty (null ptr) and calls str with "(nil)"
// If p != 0, write "0x" and convert p into hex repre (%16 and /16)
// This operation gets the remainder, which is the index for the hex base
// Decrement from back to putchar the entire number forwards

// ================== ft_hex ==================
// Use different hex base depending on whether xx is X or x
// If x = 0, write '0'
// If != 0, do the same hex conversion as ft_pointer

// ================== ft_unsigned ==================
// Takes an unsigned int and recursively /10 %10 to putchar each indiv number

#include "ft_printf.h"

void	ft_number(int num, int *len)
{
	if (num == -2147483648)
	{
		write(1, "-2147483648", 11);
		*len += 11;
	}
	else if (num < 0)
	{
		ft_putcharwlen('-', len);
		ft_number(-num, len);
	}
	else
	{
		if (num > 9)
			ft_number(num / 10, len);
		ft_putcharwlen(num % 10 + '0', len);
	}
}

void	ft_pointer(size_t p, int *len)
{
	char	string[25];
	int		i;
	char	*base_c;

	base_c = "0123456789abcdef";
	i = 0;
	if (!p)
	{
		ft_str("(nil)", len);
		return ;
	}
	write(1, "0x", 2);
	(*len) += 2;
	while (p != 0)
	{
		string[i] = base_c[p % 16];
		p = p / 16;
		i++;
	}
	while (i--)
	{
		ft_putcharwlen(string[i], len);
	}
}

void	ft_hex(unsigned int x, int *len, char xx)
{
	char	string[25];
	char	*base_c;
	int		i;

	if (xx == 'X')
		base_c = "0123456789ABCDEF";
	else
		base_c = "0123456789abcdef";
	i = 0;
	if (x == 0)
	{
		ft_putcharwlen('0', len);
		return ;
	}
	while (x != 0)
	{
		string[i] = base_c [x % 16];
		x = x / 16;
		i++;
	}
	while (i--)
		ft_putcharwlen(string[i], len);
}

void	ft_unsigned(unsigned int u, int *len)
{
	if (u >= 10)
		ft_unsigned(u / 10, len);
	ft_putcharwlen(u % 10 + '0', len);
}
