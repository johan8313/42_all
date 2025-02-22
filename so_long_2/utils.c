/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 10:25:33 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 13:19:21 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_game	map_copy(char *map_path)
{
	t_game	game_new;

	game_new.map = NULL;
	game_new.map = get_map(&game_new, map_path);
	check_if_map_is_rectangle(&game_new, game_new.map);
	return (game_new);
}

char	*get_first_line(int fd)
{
	char	*line;

	if (fd == -1)
	{
		ft_printf("Error\nFile not found or empty\n");
		return (0);
	}
	line = get_next_line(fd);
	if (!line)
	{
		ft_printf("Error\nFile empty\n");
		return (0);
	}
	return (line);
}

void	fill_list_all(char *line, t_game *game, int x, int y)
{
	if (line[x] == '\n')
		fill_list(&game->map, line[x], x, y);
	else
	{
		while (line[x] != '\n')
		{
			fill_list(&game->map, line[x], x, y);
			x++;
		}
	}
}

t_list	*get_map(t_game *game, char *map_path)
{
	int		fd;
	char	*line;
	int		x;
	int		y;

	fd = open(map_path, O_RDONLY);
	line = get_first_line(fd);
	x = 0;
	y = 0;
	while (line != NULL)
	{
		fill_list_all(line, game, x, y);
		free(line);
		x = 0;
		line = get_next_line(fd);
		y++;
	}
	close(fd);
	return (game->map);
}

void	fill_list(t_list **map, char c, int x, int y)
{
	t_list	*new_element;
	t_list	*temp;

	new_element = malloc(sizeof(*new_element));
	temp = *map;
	new_element->data = c;
	new_element->x = x;
	new_element->y = y;
	new_element->next = NULL;
	if (!(*map))
	{
		new_element->prev = NULL;
		*map = new_element;
	}
	else
	{
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		new_element->prev = temp;
		temp->next = new_element;
	}
}
