/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_possition.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:31:33 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

char	get_char_pos(t_data *so_long, t_point pos)
{
	return (so_long->map.array[pos.ypos][pos.xpos]);
}

int		ispossible_move(t_data *so_long, t_point pos_to_move)
{
	if (get_char_pos(so_long, pos_to_move) == MAP_WALL)
		return (FT_FALSE);
	else if (get_char_pos(so_long, pos_to_move) == MAP_COLLECT)
	{
		so_long->map.array[pos_to_move.ypos][pos_to_move.xpos] = MAP_EMPTY;
		so_long->state.remaining_collect--;
	}
	else if (so_long->state.remaining_collect == 0 && \
		get_char_pos(so_long, pos_to_move) == MAP_EXIT)
	{
		so_long->state.is_gameend = FT_TRUE;
	}
	return (FT_TRUE);
}

t_point     player_position(t_map *map)
{
	t_point	player_pos;
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == MAP_PLAYER)
			{
				player_pos.xpos = x;
				player_pos.ypos = y;
				return (player_pos);
			}
			x++;
		}
		y++;
	}
	player_pos.xpos = -1;
	player_pos.ypos = -1;
	return (player_pos);
}

int		s_count_collects(t_map *map)
{
	int		count;
	int		x;
	int		y;

	count = 0;
	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			if (map->array[y][x] == MAP_COLLECT)
				count++;
			x++;
		}
		y++;
	}	
	return (count);
}
