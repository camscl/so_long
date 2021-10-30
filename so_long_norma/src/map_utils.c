/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/30 23:18:15 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(t_map *map)
{
	if (map->width == (ft_lstsize(map->raw)))
		p_error("Map must be rectangular");
	return (ft_lstsize(map->raw));
}

int	checkmap_rect(t_map	*map)
{
	t_list	*raw_p;
	int		temp_content_width;

	map->height = map_height(map);
	if (map->height < 3)
		return (FT_ERROR);
	raw_p = map->raw;
	while (raw_p != NULL)
	{
		temp_content_width = ft_strlen((char *)raw_p->content);
		if (temp_content_width != map->width \
			|| temp_content_width < 3)
			return (FT_ERROR);
		raw_p = raw_p->next;
	}
	return (FT_SUCCESS);
}

int	checkmap_letters(t_map	*map)
{
	t_list	*raw_p;
	char	*temp_content;

	raw_p = map->raw;
	while (raw_p != NULL)
	{
		temp_content = raw_p->content;
		while (*temp_content)
		{
			if (ischar_map_letter(*temp_content) == FT_FALSE)
				return (FT_ERROR);
			temp_content++;
		}
		raw_p = raw_p->next;
	}
	return (FT_SUCCESS);
}

int	checkmap_walls(t_map *map)
{
	char	*raw_first_content;
	char	*raw_last_content;
	t_list	*raw_p;
	char	*temp_content;

	raw_first_content = map->raw->content;
	raw_last_content = ft_lstlast(map->raw)->content;
	if (str_map_wall(raw_first_content) == FT_FALSE \
		|| str_map_wall(raw_last_content) == FT_FALSE)
		return (FT_ERROR);
	raw_p = map->raw->next;
	while (raw_p->next != NULL)
	{
		temp_content = raw_p->content;
		if (*temp_content != MAP_WALL \
			|| *(temp_content + map->width - 1) != MAP_WALL)
			return (FT_ERROR);
		raw_p = raw_p->next;
	}
	return (FT_SUCCESS);
}

int	checkmap_essentials(t_map *map)
{
	int	check_player;
	int	check_collect;
	int	check_exit;

	check_player = count_char_in_map(map, MAP_PLAYER);
	check_collect = count_char_in_map(map, MAP_COLLECT);
	check_exit = count_char_in_map(map, MAP_EXIT);
	if (!(check_player == 1 && check_collect >= 1 && check_exit == 1))
		return (FT_ERROR);
	return (FT_SUCCESS);
}
