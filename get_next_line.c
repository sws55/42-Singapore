/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:31 by sebwong           #+#    #+#             */
/*   Updated: 2023/10/18 10:40:32 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
memory is allocated and chars are repeatedly read into "big" and joined 
together until newline is detected, even if the read contains chars that
are beyond the newline.

memory adr is updated to the point including the newline.

memory is allocated again to "small" and the part including the newline
is transferred into "small" from "big".

value of "big" is updated to after the newline.

"small" is returned while reading continues until the next newline and
until the null terminator.
*/
#include "get_next_line.h"


char *ft_read(big)
{ 
	//read file until reach a newline, then stop and call a function to process the string
	int bytesRead;

	while (file != '\0')
	{
		int bytesRead = read(fd, big, BUFFER_SIZE);
		ft_strchr(bytesRead, "\n");
	}
}

char *get_next_line(int fd)
{
	char *big;

	//chars from file are read into big
	big = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (big == NULL)
		return (NULL);

	//newline is identified and reading is stopped

	//transfer the line chars into a new variable and remove them from the 
	//static var and leave only the post-newline chars inside
	//return the line chars to the main func
	return (line);
}

int main()
{
	int count;
	char *line;
	int	fd;

	line = NULL;
	count = 0;
	//Opening the file called testfile with the permission to read only
	fd = open("testfile.txt", O_RDONLY);
	while (1)
	{
		if (fd == -1)
		{
			printf("Cannot open file\n");
			exit(0);
		}

		line = get_next_line(fd);
		count++;
	    printf("[%d]: %s\n", count, line);
	    line = NULL;
	}
	

    close (fd);
	return(0);
}
