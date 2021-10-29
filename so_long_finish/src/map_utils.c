/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:52:08 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	map_height(t_map *map)
{
	return (ft_lstsize(map->raw));
}

t_bool	ischar_map_letter(char c)
{
	if (c == MAP_EMPTY \
		|| c == MAP_WALL \
		|| c == MAP_COLLECT \
		|| c == MAP_EXIT \
		|| c == MAP_PLAYER)
		return (FT_TRUE);
	return (FT_FALSE);
}
t_bool	str_map_wall(char *str)
{
	while (*str)
	{
		if (*str != MAP_WALL)
			return (FT_FALSE);
		str++;
	}
	return (FT_TRUE);
}

int	count_char_in_map(t_map *map, char c)
{
	int		count;
	t_list	*raw_p;
	char	*temp_content;

	count = 0;
	raw_p = map->raw;
	while (raw_p != NULL)
	{
		temp_content = (char *)(raw_p->content);
		while (*temp_content)
		{
			if (*temp_content == c)
				count++;
			temp_content++;
		}
		raw_p = raw_p->next;
	}
	return (count);
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
