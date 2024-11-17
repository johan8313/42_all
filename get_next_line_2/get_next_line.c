/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/13 10:56:09 by johmarti          #+#    #+#             */
/*   Updated: 2024/02/19 11:38:39 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char		*buffer;
	char			*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
		return (NULL);
	buffer = ft_read_file(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_read_line(buffer);
	buffer = ft_next_line(buffer);
	return (line);
}
/*
#include <fcntl.h>
#include <stdio.h>

int	main()
{
	int	fd;
	//int	i;
	//char	*buffer;
	char	*line;
	//char	*next_line;

	fd = open("text.txt", O_RDONLY);
	//printf("FIRST_LINE\n%s", get_next_line(fd));
	//printf("NEXT_LINE\n%s", get_next_line(fd));
	//printf("NEXT_LINE\n%s\n", get_next_line(fd));
	//printf("NEXT_LINE\n%s\n", get_next_line(fd));
	while ((line = get_next_line(fd)) != NULL)
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
/*
char *ft_read_file(int fd, buffer)
{
	//size_t	nbytes;
	char	*buf;
	buf = malloc(sizeof(*buf) * (BUFFER_SIZE + 1));
	char	*line;
	static char *stash;

	while (!ft_strchr(buf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		//printf("%ld\n", nbytes);
		//printf("%s\n", buf);
	}
	//printf("%s\n", buf);
	line = ft_extract_line (buf);
	stash = malloc(sizeof(char) * ((int)ft_strlen(ft_strchr(buf, '\n'))));
	stash = ft_strchr(buf, '\n');
	printf("%s\n",stash);
return (line);
	//buf = ft_strchr(buf, '\n');
	//printf("%s\n", buf);
	//printf("%s\n", ft_strchr(buf, '\n'));
	//printf("%ld\n", nbytes);
	//printf("%s\n", buf);
}
*/

/*
char *ft_extract_line (char *buf)
{
	int i;
	char *line;

	i = 0;
	line = malloc(sizeof(char) *
				(((int)ft_strlen(buf) -
				(int)ft_strlen(ft_strchr(buf, '\n')))) + 1);
	//printf("%li\n", ft_strlen(line));
	while (buf[i] != '\n')
	{
		//printf("%c", line[i]);
		line[i] = buf[i];
		//printf("%c", line[i]);
		i++;
	}
	//printf("%li\n", ft_strlen(line));
	//line[i] = '\n';
	//line[i + 1] = '\0';
	return (line);
}
*/

/*
char	*ft_read_file(int fd, char *buffer)
{
	//int		bytes_read;
	char	*buf;

	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(*buf));
	while (!ft_strchr(buf, '\n'))
	{
		read(fd, buf, BUFFER_SIZE);
		buffer = ft_strjoin(buffer, buf);
		//free(buffer);
	}
	free(buf);

	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = 0;
		buffer = ft_free(buffer, buf);
		if(ft_strchr(buf, '\n'))
			break ;
	}
	free(buf);

return (buffer);
}*/
