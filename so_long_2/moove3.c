/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/27 11:39:04 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 14:00:58 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove_up_win(t_game *game)
{
	t_list	*map;
	int		i;

	map = game->map;
	while (map->data != 'P')
		map = map->next;
	i = game->x_max;
	if (data_up_p(game, map) != '1')
	{
		map->data = '0';
		while (i >= 0)
		{
			map = map->prev;
			i--;
		}
		game->count_mooves += 1;
		ft_printf("Nbr of mooves : %d\n", game->count_mooves);
		if (map->data == 'E')
		{
			ft_printf("You won!\n");
			free_game(game, 1);
		}
		map->data = 'P';
	}
}

void	moove_down_win(t_game *game)
{
	t_list	*map;
	int		i;

	map = game->map;
	while (map->data != 'P')
		map = map->next;
	i = 0;
	if (data_down_p(game, map) != '1')
	{
		map->data = '0';
		while (i <= game->x_max)
		{
			map = map->next;
			i++;
		}
		game->count_mooves += 1;
		ft_printf("Nbr of mooves : %d\n", game->count_mooves);
		if (map->data == 'E')
		{
			ft_printf("You won!\n");
			free_game(game, 1);
		}
		map->data = 'P';
	}
}

void	moove_right_win(t_game *game)
{
	t_list	*map;

	map = game->map;
	while (map->data != 'P')
		map = map->next;
	if (data_next_p(map) != '1')
	{
		map->data = '0';
		map = map->next;
		game->count_mooves += 1;
		ft_printf("Nbr of mooves : %d\n", game->count_mooves);
		if (map->data == 'E')
		{
			ft_printf("You won!\n");
			free_game(game, 1);
		}
		map->data = 'P';
	}
}

void	moove_left_win(t_game *game)
{
	t_list	*map;

	map = game->map;
	while (map->data != 'P')
		map = map->next;
	if (data_prev_p(map) != '1')
	{
		map->data = '0';
		map = map->prev;
		game->count_mooves += 1;
		ft_printf("Nbr of mooves : %d\n", game->count_mooves);
		if (map->data == 'E')
		{
			ft_printf("You won!\n");
			free_game(game, 1);
		}
		map->data = 'P';
	}
}

int	free_game2(t_game *game)
{
	free_map(&game->map);
	mlx_destroy_image(game->mlx, game->img.wall);
	mlx_destroy_image(game->mlx, game->img.empty);
	mlx_destroy_image(game->mlx, game->img.exit);
	mlx_destroy_image(game->mlx, game->img.characters);
	mlx_destroy_image(game->mlx, game->img.coin);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}
