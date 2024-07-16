/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/25 12:13:48 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/25 12:13:49 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// Number of % signs in the printf statement = number of args in the function
// args = argument pointer, str = an argument which defines number of arguments
// va_list ap; initializes the pointer to a series of arguments
// va_start makes ap skip num and point to the first argument
// va_arg increments to and fetches the next argument, 
// input data type to know how many bytes required
// va_end cleans up data
// char -> int/unsigned int & float -> double

#include "ft_printf.h"

static void	ft_printf_check(char s, va_list *args, int *len, int *i)
{
	if (s == 'c')
		ft_putcharwlen(va_arg(*args, int), len);
	else if (s == 's')
		ft_str(va_arg(*args, char *), len);
	else if (s == 'p')
		ft_pointer(va_arg(*args, size_t), len);
	else if (s == 'd' || s == 'i')
		ft_number(va_arg(*args, int), len);
	else if (s == 'u')
		ft_unsigned(va_arg(*args, unsigned int), len);
	else if (s == 'x')
		ft_hex(va_arg(*args, unsigned int), len, 'x');
	else if (s == 'X')
		ft_hex(va_arg(*args, unsigned int), len, 'X');
	else if (s == '%')
		ft_putcharwlen('%', len);
	else
		(*i)--;
}

// ft_printf("%s is a %s dick", "something")
// ft_printf("sdfsfs")
int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		len;

	i = 0;
	len = 0;
	va_start(args, str);
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			ft_printf_check(str[i], &args, &len, &i);
			i++;
		}
		else
		{
			ft_putcharwlen((char)str[i], &len);
			i++;
		}
	}
	va_end(args);
	return (len);
}
