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


char	*identify()

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

//this function transfers everything before the newline
//from the static variable to another variable
char	*ft_pre_nl()

//this function updates the static variable to everything
//after the newline
char	*ft_post_nl()

//after that, join the new characters 



char *get_next_line(int fd)
{
	char *big;

	//chars from file are read into big
	big = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (big == NULL)
		return (NULL);

	//newline is identified and reading is stopped
	ft_identifier(big, "\n");

	//transfer the line chars into a new variable and remove them from the 
	//static var and leave only the post-newline chars inside
	ft_pre()
	ft_post()

	//return the line chars to the main func
	return (line);
}
/*
//In the test function, the file is opened and GNL is repeatedly called until the end of file 
char  *get_next_line(int fd)
{
  int  bytes_read;
  char *cup_buffer;
  
  cup_buffer = ft_calloc(3 + 1, sizeof(char));
  if (!cup_buffer)
    return (NULL);
  bytes_read = read(fd, cup_buffer, 3);
  if (bytes_read <= 0)
    return (NULL);
  return (cup_buffer);
}
*/
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
