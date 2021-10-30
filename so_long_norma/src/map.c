/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/30 23:26:03 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../so_long.h"

static void	map_extension(char *filname)
{
	char	*name;

	name = ft_strnstr(filname, ".ber", ft_strlen(filname));
	if (name == NULL)
		p_error("Invalid file extension");
}

static void	read_map(int filde, t_map *map)
{
	char	*buf;
	int		result;

	map->width = 0;
	map->raw = ft_lstnew(NULL);
	result = get_next_line(filde, &buf);
	while (result != FT_EOF)
	{
		if (map->width == 0)
			map->width = ft_strlen(buf);
		ft_lstadd_back(&(map->raw), ft_lstnew((void *)buf));
		result = get_next_line(filde, &buf);
	}
}

static void	validate_map(t_map *map)
{
	if (checkmap_rect(map) == FT_ERROR)
		p_error("Invalid map, more height");
	if (checkmap_letters(map) == FT_ERROR)
		p_error("Characteres not correct");
	if (checkmap_walls(map) == FT_ERROR)
		p_error("Invalid map. Maps are not walled up.");
	if (checkmap_essentials(map) == FT_ERROR)
		p_error("The map must have P, E and C.");
}

static void	sl_raw_to_array_map(t_map *map)
{
	t_list	*raw_p;
	int		i;

	raw_p = map->raw;
	map->array = (char **)malloc(sizeof(char *) * map->height);
	i = 0;
	while (i < map->height)
	{
		*((map->array) + i) = (char *)raw_p->content;
		i++;
		raw_p = raw_p->next;
	}
}

void	p_map(char *map_name, t_data *so_long)
{
	int	filde;

	map_extension(map_name);
	filde = open(map_name, O_RDONLY);
	if (filde == 0)
		p_error("Map file not found");
	else
	{
		read_map(filde, &(so_long->map));
		print_a_message("Read file exited");
		validate_map(&(so_long->map));
		print_a_message("The map is ready");
		sl_raw_to_array_map(&(so_long->map));
		print_a_message("Map");
		print_map_array(&(so_long->map));
	}
}
