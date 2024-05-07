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

// ft_read is a function that reads from the file descriptor into the buffer
// bigstore until it reaches a '\n' or '\0' and returns the buffer
char	*ft_read(int fd, char *bigstore)
{
	int			bytesread;
	char		*smallstore;
	char		*temp;

	// allocate memory for the temp buffer smallstore
	smallstore = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	// if memory allocation fails, return NULL
	if (smallstore == NULL)
		return (NULL);
	// set bytesread to 1 to start the loop, even if there are no bytes to read, or EOF
	bytesread = 1;
	// while there are bytes to read and there is no '\n' in smallstore
	while (bytesread > 0 && ft_strchr(smallstore, '\n') == NULL)
	{
		// read from the file descriptor into smallstore
		bytesread = read(fd, smallstore, BUFFER_SIZE);
		// if read fails, free smallstore and bigstore and return NULL
		if (bytesread < 0)
		{
			free (smallstore);
			free (bigstore);
			return (NULL);
		}
		// null terminate smallstore up until the point where it reads past the '\n' or '\0'
		smallstore[bytesread] = '\0';
		// join the contents of bigstore and smallstore into temp
		temp = ft_strjoin(bigstore, smallstore);
		// free bigstore of the old memory
		free (bigstore);
		// copy the contents of temp into bigstore
		bigstore = ft_strdup(temp);
		// free temp
		free (temp);
	}
	// free smallstore and return bigstore
	free (smallstore);
	return (bigstore);
}

// this function effectively chops what is read into the buffer so far and returns the line
// by copying the chars from bigstore into line until '\n' or '\0' and leaving the rest
char	*ft_getline(char *bigstore)
{
	char	*line;
	int		len;

	len = 0;
	// while the char is not '\n' or '\0', increment i to get length of line
	while (bigstore[len] != '\n' && bigstore[len] != '\0')
		len++;
	// allocate memory for one line in the buffer as big as up until '\n' or '\0'
	line = (char *)malloc(sizeof(char) * (len + 1));
	// if memory allocation fails, return NULL
	if (line == NULL)
		return (NULL);
	// reset len to 0 to copy the chars from bigstore into line until '\n' or '\0'
	len = 0;
	// copy the chars from bigstore into line including '\n' or '\0'
	while (bigstore[len] != '\n' && bigstore[len] != '\0')
	{
		ft_strlcpy(line, bigstore, len + 1);
		len++;
	}
	// null terminate & return the line
	line[len] = '\0';
	return (line);
}

// ft_next is a function that moves the pointer to the next line
// by updating the value of bigstore and returning it
char	*ft_next(char *bigstore)
{
	char	*temp;
	char	*nextline;

	// nextline contains a ptr to the first '\n' in bigstore
	nextline = ft_strchr(bigstore, '\n');
	// copy the next line into temp, starting from the char after '\n'
	// strdup copies the string + 1 for the '\n' or the '\0'
	temp = ft_strdup(nextline + 1);
	free (bigstore);
	// copy the temp back into bigstore to move the pointer to
	// the start of the next line
	bigstore = ft_strdup(temp);
	free (temp);
	return (bigstore);
}

// the get_next_line function does error handling for the buffer
// and file descriptor, initialises the buffer bigstore
char *get_next_line(int fd)
{
	static char *bigstore;
	char *line;
	// error checking for file descriptor & buffer size
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, bigstore, 0) < 0)
		return (NULL);
	// initialise & allocate memory once for the buffer bigstore + 1 for
	// a '\n' after each line & '\0' at the end
	if (bigstore == NULL)
		bigstore = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	// read from the file descriptor into the buffer bigstore
	bigstore = ft_read(fd, bigstore);
	// error checking in case ft_read does not read any more chars
	if (ft_read == NULL)
	{
		free (bigstore);
		bigstore = NULL;
		return (NULL);
	}
	// error checking for memory allocation
	if (bigstore == NULL)
	{
		free (bigstore);
		bigstore = NULL;
		return (NULL);
	}
	// return the result of ft_getline into the variable line
	line = ft_getline(bigstore);
	// if there are no more new lines from ft_detect, free bigstore
	if (ft_getline == NULL)
	{
		free (bigstore);
		bigstore = NULL;
		return (NULL);
	}
	// moving the pointer to the next line using the function ft_next
	bigstore = ft_next(bigstore);
	// return the line
	return (line);
}

/*
//In the test function, the file is opened and GNL is repeatedly called until the end of file 
int main()
{
	int count;
	char line;
	int	fd;

	//Opening the file called testfile with the permission to read only
	fd = fopen("testfile.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("Cannot open file\n");
		exit(0);
	}
	while (1)
	{
		line = get_next_line(fd);
		count++;
	    printf("[%d]: %s\n", count, line)
	    line == NULL;
	}
    close (fd);
	return(0);
}
*/