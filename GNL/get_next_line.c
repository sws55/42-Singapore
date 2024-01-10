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

#include "get_next_line.h"

char *ft_identifier(storage)
{

}

char *ft_read(storage)
{
	//read file until reach a newline, then stop and call a function to process the string
	int bytesRead;

	while (file != '\0')
	{
		int bytesRead = read(fd, storage, BUFFER_SIZE);
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
	static char *storage;

	//chars from file are read into the static var
	storage = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (storage == NULL)
		return (NULL);

	//newline is identified and reading is stopped
	ft_identifier(storage, "\n");

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
