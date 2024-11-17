/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 10:58:15 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/19 11:35:35 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_join_free(char *buffer, char *buf)
{
	char	*temp;

	temp = ft_strjoin(buffer, buf);
	free(buffer);
	return (temp);
}

char	*ft_read_file(int fd, char *buffer)
{
	char	*buf;
	int		bytes_read;

	if (!buffer)
		buffer = ft_calloc(1, 1);
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	bytes_read = 1;
	while (bytes_read)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buffer);
			return (NULL);
		}
		buf[bytes_read] = 0;
		buffer = ft_join_free(buffer, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);
	return (buffer);
}

char	*ft_read_line(char *buffer)
{
	int		i;
	char	*line;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = ft_calloc((i + 2), sizeof(*line));
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
	int		i;
	int		j;
	char	*line;

	i = 0;
	while (buffer [i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	line = ft_calloc((ft_strlen(buffer) - i + 1), sizeof(*line));
	i++;
	j = 0;
	while (buffer[i])
		line[j++] = buffer[i++];
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	static char		*buffer[FD_SETSIZE];
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer[fd] = ft_read_file(fd, buffer[fd]);
	line = ft_read_line(buffer[fd]);
	buffer[fd] = ft_next_line(buffer[fd]);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	//int	i;
	int		file[2];
	int		fd;
	int		fd_bonus;
	char	*line;
	//char	*next_line;

	fd = open("text1.txt", O_RDONLY);
	fd_bonus = open("text2.txt", O_RDONLY);

	file[0] = fd;
	file[1] = fd_bonus;

	//printf("FIRST_LINE\n%s", get_next_line(fd));
	//printf("NEXT_LINE\n%s", get_next_line(fd));
	//printf("NEXT_LINE\n%s\n", get_next_line(fd));
	//printf("NEXT_LINE\n%s\n", get_next_line(fd));
	while ((line = get_next_line(*file)) != NULL)
		printf("<> %s", line);
	while ((line = get_next_line(*(file + 1))) != NULL)
		printf("<> %s", line);
	//buffer = malloc(sizeof(*buffer) *BUFFER_SIZE);
	//buffer = ft_read_file(fd, buffer);
	//printf("BUFFER_READ\n%s", buffer);
	//i = 0;
	//while (buffer[i] != '\n')
	//	i++;
	//line = malloc(sizeof(*line) * (i + 1));
	//line = ft_read_line(buffer);

	//static	char	*buffer;
	//printf("FIRST_LINE\n%s", line);
	//next_line = ft_next_line(buffer);
	//printf("NEXT_LINE\n%s", next_line);
	//free(buffer);
	//free(line);
}
*/
