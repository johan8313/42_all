/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/26 09:49:31 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 15:49:57 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_list	*get_node(t_game *game, int x, int y)
{
	t_list	*current;

	current = game->map;
	while (current != NULL)
	{
		if (current->x == x && current->y == y)
			return (current);
		current = current->next;
	}
	return (NULL);
}

void	move_on_paths(int x, int y, t_game *game)
{
	char	data;

	data = get_node(game, x, y)->data;
	if (data == 'C')
	{
		game->count_c -= 1;
		get_node(game, x, y)->data = '1';
	}
	else if (data == '0' || data == 'P')
		get_node(game, x, y)->data = '1';
	else
		return ;
	move_on_paths(x + 1, y, game);
	move_on_paths(x - 1, y, game);
	move_on_paths(x, y + 1, game);
	move_on_paths(x, y - 1, game);
}

void	move_on_paths2(int x, int y, t_game *game)
{
	char	data;

	data = get_node(game, x, y)->data;
	if (data == 'E')
	{
		game->count_e -= 1;
		get_node(game, x, y)->data = '1';
	}
	else if (data == '0' || data == 'P')
		get_node(game, x, y)->data = '1';
	else
		return ;
	move_on_paths(x + 1, y, game);
	move_on_paths(x - 1, y, game);
	move_on_paths(x, y + 1, game);
	move_on_paths(x, y - 1, game);
}

t_list	*go_to_p_data(t_list *current)
{
	while (current != NULL)
	{
		if (current->data == 'P')
			break ;
		current = current->next;
	}
	return (current);
}

int	check_valid_path(char *arg)
{
	t_game	game;
	t_list	*start;
	t_list	*start2;
	t_list	*current;

	game_init2(&game, arg);
	start = NULL;
	current = game.map;
	current = go_to_p_data(current);
	start = current;
	start2 = current;
	check_map_elements(&game, game.map);
	move_on_paths(start->x, start->y, &game);
	move_on_paths2(start2->x, start2->y, &game);
	if (game.count_c != 0)
	{
		free_map(&game.map);
		return (0);
	}
	free_map(&game.map);
	return (1);
}
