/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils_plus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/30 23:55:28 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

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
