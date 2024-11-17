/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map3.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 15:26:46 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 15:31:14 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_file_format(char *map_path)
{
	int	end;

	end = ft_strlen(map_path);
	if (map_path[end - 4] != '.' || map_path[end - 3] != 'b'
		|| map_path[end - 2] != 'e' || map_path[end - 1] != 'r')
		return (0);
	return (1);
}

void	game_init2(t_game *game, char *arg)
{
	game->map = NULL;
	game->map = get_map(game, arg);
	game->count_c = 0;
	game->count_p = 0;
	game->count_e = 0;
	game->count_mooves = 0;
}
