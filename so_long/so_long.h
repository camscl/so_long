/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:31:41 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <errno.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>

# include "libs/mlx/mlx.h"
# include "libs/libft/libft.h"
# include "libs/get_next_line/get_next_line.h"

/*
** keycodes 
** ESC: exit 
** Q: exit 
** ARROW KEYS: move player
** WASD: move player
** CLOSE_BUTTON: the red close button at window bar
** 
*/
# define KEY_ESC			53
# define KEY_Q				12
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define KEY_ARROW_UP		126
# define KEY_ARROW_DOWN		125
# define KEY_ARROW_LEFT		123
# define KEY_ARROW_RIGHT	124
# define CLOSE_BUTTON		17

/*
** map sources
*/
# define MAP_TILE_SIZE		50
# define MAP_SRC_PLAYER		'image/player.png'
# define MAP_SRC_COLLECT	'image/collect.png'
# define MAP_SRC_WALL		'image/wall.png'
# define MAP_SRC_EXIT		'image/exit.png'
# define MAP_COLOR_BG		0x00DFFFF4
# define MAP_COLOR_TEXT		0x00D9625B
# define DECIMAL_BASE		"0123456789"

/*
** .ber file characters
*/
# define MAP_PLAYER		'P'
# define MAP_COLLECT	'C'
# define MAP_EMPTY		'0'
# define MAP_WALL		'1'
# define MAP_EXIT		'E'

/*
** ANSI Color Codes
*/
# define RED			"\x1b[31m"
# define GREEN			"\x1b[32m"
# define BLUE			"\x1b[34m"
# define YELLOW			"\x1b[33m"
# define MAGENTA		"\x1b[35m"
# define CYAN			"\x1b[36m"
# define RESET			"\x1b[0m"

typedef struct s_point
{
	int	xpos;
	int	ypos;
}				t_point;

typedef struct s_img
{
	void		*img_ptr;
	int			*addr;
	int			size_line;
	int			bits_per_pixel;
	int			endian;
}				t_img;

typedef struct s_objects
{
	void	*player;
	void	*collect;
	void	*wall;
	void	*exit;
}				t_objects;

typedef struct s_map
{
	t_list		*raw;
	char		**array;
	int			width;
	int			height;
	t_img		background;
	t_objects	objects;
}				t_map;

typedef struct s_state
{
	t_point		player_pos;
	int			remaining_collect;
	int			move_count;
	t_bool		is_gameend;
}				t_state;

typedef struct s_data
{
	void	*mlx;
	void	*win;
	t_map	map;
	int		win_width;
	int		win_height;
	t_state	state;
}				t_data;



void	s_exit(t_data *state);
int		p_error(char *message);
int		s_exit_button(t_data *so_long);
void	s_the_end(t_data *so_long);

/*
** map
*/
void	p_map(char *map_filename, t_data *so_long);

int		checkmap_rect(t_map	*map);
int		checkmap_letters(t_map	*map);
int		checkmap_walls(t_map *map);
int		checkmap_essentials(t_map *map);

int		map_height(t_map *map);
t_bool	ischar_map_letter(char c);
t_bool	str_map_wall(char *str);
int		count_char_in_map(t_map *map, char c);

char	get_char_pos(t_data *so_long, t_point pos);
int		ispossible_move(t_data *so_long, t_point pos_to_move);
t_point	player_position(t_map *map);
int		s_count_collects(t_map *map);

/*
** graphic
*/
void	s_init_images(t_data *so_long);
void	s_draw_frame(t_data *so_long);
//char	*sl_itoa(int nbr, char *buf);

/*
** print in shell
*/
void	print_counter(t_data *so_long);
void	print_a_message(char *message);
void	print_map_array(t_map *map);

/*
** input
*/
int		skey_hook(int keycode, t_data *state);

#endif