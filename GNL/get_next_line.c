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
		int bytesRead = read(fd, storage, 3);

}



char *get_next_line(int fd)
{
	static char *storage;

	//chars from file are read into the static var
	storage = ft_calloc(BUFFER_SIZE + 1 * ())

	//newline is identified and reading is stopped

	//transfer the line chars into a new variable and remove them from the 
	//static var and leave only the post-newline chars inside

	storage = ft_read(XXX) //Everything including things after /n

	//return the line chars to the main func
	return (line);
}




//In the test function, the file is opened and GNL is repeatedly called until the end of file 
int main()
{
	int count;
	char line;
	int	fd;

	//Opening the file called testfile with the permission to read only
	fd = fopen("testfile.txt", "r");
	while (1)
	{
		if (fd == NULL)
		{
			printf("Cannot open file\n");
			exit(0);
		}

		line = get_next_line(fd);
		count++;
	    printf("[%d]: %s\n", count, line)
	    line == NULL;
	}
	

    close (fd);
	return(0);
}
*/