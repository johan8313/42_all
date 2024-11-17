/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:56:09 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/22 13:39:59 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read_file(int fd, char *buffer)
{
	char	buf[BUFFER_SIZE + 1];
	int		bytes_read;

	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			if (buffer)
				free(buffer);
			return (NULL);
		}
		if (bytes_read == 0)
			break ;
		buf[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (buffer);
}

char	*ft_read_line(char *buffer)
{
	size_t		i;
	char		*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		++i;
	line = (char *)malloc((i + 2) * sizeof(*line));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		++i;
	}
	if (buffer[i] == '\n')
		line[i++] = '\n';
	else
		line[i++] = '\0';
	line[i] = '\0';
	return (line);
}

char	*ft_next_line(char *buffer)
{
	size_t		i;
	size_t		j;
	char		*line;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		++i;
	if (buffer[i] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	line = (char *)malloc((ft_strlen(buffer) - i + 1) * sizeof(*line));
	if (!line)
	{
		free(buffer);
		return (NULL);
	}
	j = 0;
	++i;
	while (buffer[i])
		line[j++] = buffer[i++];
	line[j] = '\0';
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer[FD_SETSIZE];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || fd > FD_SETSIZE)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_read_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int		fd;
	char	*line;

	fd = open("text.txt", O_RDONLY);
	while ((line = get_next_line(fd)) != NULL)
	{
	printf("<> %s", line);
	free(line);
	}
}
*/
