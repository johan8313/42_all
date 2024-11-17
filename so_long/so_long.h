/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: johmarti <johmarti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 12:22:37 by johmarti          #+#    #+#             */
/*   Updated: 2024/04/11 15:49:36 by johmarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include "libft/get_next_line_bonus.h"
# include "libft/ft_printf.h"

typedef struct s_list_s
{
	struct s_list_s	*next;
	struct s_list_s	*prev;
	char			data;
	int				x;
	int				y;
	int				visited;
}					t_list;

typedef struct s_path
{
	char		*wall;
	char		*characters;
	char		*coin;
	char		*empty;
	char		*exit;
}				t_path;

typedef struct s_image
{
	t_path		path;
	void		*wall;
	void		*characters;
	void		*coin;
	void		*empty;
	void		*exit;
}				t_images;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			img_width;
	int			img_height;
	int			x_max;
	int			y_max;
	t_list		*map;
	t_images	img;
	int			count_c;
	int			count_e;
	int			count_p;
	int			count_mooves;
}				t_game;

//map1
int		check_map(t_game *game, char *map_path);
int		check_if_map_is_rectangle(t_game *game, t_list *map);
int		check_map_data(t_list *map);
int		check_map_elements(t_game *game, t_list *map);
int		check_if_map_walled(t_game *game, t_list *map);

//map2
t_list	*get_node(t_game *game, int x, int y);
void	move_on_paths(int x, int y, t_game *game);
void	move_on_paths2(int x, int y, t_game *game);
t_list	*go_to_p_data(t_list *current);
int		check_valid_path(char *arg);

//map3
int		check_file_format(char *map_path);
void	game_init2(t_game *game, char *arg);

//main
void	game_init(t_game *game);
void	free_map(t_list **map);
void	game_launch(t_game *game);
int		free_game(t_game *game, int type);
void	game_init2(t_game *game, char *arg);

//image
void	image_path(t_game *game);
void	set_img(t_game *game);
void	xpm_to_image1(t_game *game);
int		pop_window(t_game *game);

//utils
t_game	map_copy(char *map_path);
char	*get_first_line(int fd);
t_list	*get_map(t_game *game, char *map_path);
void	fill_list(t_list **map, char c, int x, int y);
void	fill_list_all(char *line, t_game *game, int x, int y);

//moove1
int		handle_keypress(int keysym, t_game *game);
char	data_up_p(t_game *game, t_list *map);
char	data_down_p(t_game *game, t_list *map);
char	data_next_p(t_list *map);
char	data_prev_p(t_list *map);

//moove2
void	moove_up(t_game *game);
void	moove_down(t_game *game);
void	moove_right(t_game *game);
void	moove_left(t_game *game);

//moove3
void	moove_up_win(t_game *game);
void	moove_down_win(t_game *game);
void	moove_right_win(t_game *game);
void	moove_left_win(t_game *game);
int		free_game2(t_game *game);

#endif
