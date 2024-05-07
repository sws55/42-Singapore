/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/29 15:07:03 by sebwong           #+#    #+#             */
/*   Updated: 2023/12/29 15:07:04 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	GET_NEXT_LINE_H
#   define	GET_NEXT_LINE_H

#ifndef BUFFER_SIZE
#   define BUFFER_SIZE 10
#endif

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

char	*get_next_line(int fd);
char	*ft_calloc(size_t element, size_t size);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strjoin(char *s1, char *s2);

#endif