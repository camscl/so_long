/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:41:05 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	s_putbackground_image(t_data *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->win);
	mlx_put_image_to_window(so_long->mlx, so_long->win, so_long->map.background.img_ptr, 0, 0);
}
static void	s_put_image(t_data *so_long, void *img_ptr, t_point *img_pos)
{
	mlx_put_image_to_window(so_long->mlx, so_long->win, img_ptr, \
		img_pos->xpos * MAP_TILE_SIZE, img_pos->ypos * MAP_TILE_SIZE);

}

static void	s_put_image_with_map_data(\
	t_data *so_long, char map_char, t_point *img_pos)
{
	if (map_char == MAP_WALL)
		s_put_image(so_long, so_long->map.objects.wall, img_pos);
	else if (map_char == MAP_EXIT)
		s_put_image(so_long, so_long->map.objects.exit, img_pos);
	else if (map_char == MAP_COLLECT)
		s_put_image(so_long, so_long->map.objects.collect, img_pos);
}


static void	s_put_object_img(t_data *so_long)
{
	int		x;
	int		y;
	t_point	pos;
	char	c;

	y = 0;
	while (y < so_long->map.height)
	{
		x = 0;
		while (x < so_long->map.width)
		{
			pos.xpos = x;
			pos.ypos = y;
			c = get_char_pos(so_long, pos);
			s_put_image_with_map_data(so_long, c, &pos);
			x++;
		}
		y++;
	}
}
void	s_draw_frame(t_data *so_long)
{
	mlx_clear_window(so_long->mlx, so_long->win);
	s_putbackground_image(so_long);
	s_put_object_img(so_long);
	s_put_image(so_long, so_long->map.objects.player, \
		&(so_long->state.player_pos));
}
