/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sebwong <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 10:40:31 by sebwong           #+#    #+#             */
/*   Updated: 2024/05/09 14:05:19 by sebwong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	size_t	len1;
	size_t	len2;
	char	*result;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = 0;
	while (s1[len1])
		len1++;
	len2 = 0;
	while (s2[len2])
		len2++;
	result = (char *)malloc(len1 + len2 + 1);
	if (result == NULL)
		return (NULL);
	ft_strlcpy(result, s1, len1 + len2 + 1);
	ft_strlcpy(result + len1, s2, len2 + 1);
	free (s1);
	s1 = NULL;
	return (result);
}

char	*ft_read(int fd, char *bigstore)
{
	int		bytesread;
	char	*smallstore;
	char	*temp;

	smallstore = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!smallstore)
		return (NULL);
	bytesread = 1;
	while (bytesread > 0 && ft_strchr(smallstore, '\n') == NULL)
	{
		bytesread = read(fd, smallstore, BUFFER_SIZE);
		if (bytesread < 0)
		{
			free(smallstore);
			smallstore = NULL;
			return (free(bigstore), bigstore = NULL, NULL);
		}
		smallstore[bytesread] = '\0';
		temp = ft_strjoin_free(bigstore, smallstore);
		bigstore = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	return (free(smallstore), smallstore = NULL, bigstore);
}

char	*ft_getline(char **bigstore)
{
	char	*line;
	int		len;

	len = 0;
	while ((*bigstore)[len] != '\n' && (*bigstore)[len] != '\0')
		len++;
	len = len + 1;
	line = (char *)ft_calloc(len + 1, sizeof(char));
	if (line == NULL)
		return (NULL);
	ft_strlcpy(line, *bigstore, len + 1);
	line[len] = '\0';
	if (!ft_strchr(*bigstore, '\n'))
	{
		free(*bigstore);
		*bigstore = NULL;
	}
	return (line);
}

char	*ft_next(char *bigstore)
{
	char	*temp;
	char	*nextline;

	if (bigstore)
	{
		nextline = ft_strchr(bigstore, '\n');
		temp = ft_strdup(nextline + 1);
		free(bigstore);
		bigstore = NULL;
		bigstore = ft_strdup(temp);
		free(temp);
		temp = NULL;
	}
	return (bigstore);
}

char	*get_next_line(int fd)
{
	static char	*bigstore;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (bigstore == NULL)
		bigstore = (char *)ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	bigstore = ft_read(fd, bigstore);
	if (bigstore == NULL || *bigstore == '\0')
		return (free(bigstore), bigstore = NULL, NULL);
	line = ft_getline(&bigstore);
	bigstore = ft_next(bigstore);
	return (line);
}

int main()
{
	int fd = open("a.txt", O_RDONLY);
	char *a;

	while ((a = get_next_line(fd)))
	{
		printf("%s", a);
	}

	// printf("%s", get_next_line(fd));

	return 0;
}
