/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/29 11:20:48 by sebwong           #+#    #+#             */
/*   Updated: 2023/09/29 11:20:49 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stddef.h>
# include <stdlib.h>
# include <stdio.h>

void	ft_putcharwlen(char c, int *len);
void	ft_str(char *s, int *len);

void	ft_number(int num, int *len);
void	ft_unsigned(unsigned int u, int *len);
void	ft_pointer(size_t p, int *len);
void	ft_hex(unsigned int x, int *len, char xx);

int		ft_printf(const char *str, ...);

#endif