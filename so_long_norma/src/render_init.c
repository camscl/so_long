/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/30 22:50:26 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	color_image(t_img *image, int width, int height, int color)
{
	int	h;
	int	w;

	h = 0;
	while (h < height)
	{
		w = 0;
		while (w < width)
		{
			image->addr[h * width + w] = color;
			w++;
		}
		h++;
	}
}

static void	set_bg_image(t_data *so_long)
{
	int	bg_height;
	int	bg_width;

	bg_height = so_long->win_height + 50;
	bg_width = so_long->win_width;
	so_long->map.background.img_ptr = mlx_new_image(so_long->mlx, \
		bg_width, bg_height);
	if (so_long->map.background.img_ptr == NULL)
		p_error("Failed to load the background image.");
	so_long->map.background.addr = (int *)mlx_get_data_addr(\
		so_long->map.background.img_ptr, \
		&so_long->map.background.bits_per_pixel, \
		&so_long->map.background.size_line, \
		&so_long->map.background.endian);
	color_image(&(so_long->map.background), \
		bg_width, bg_height, MAP_COLOR_BG);
}

static void	*get_png_image(t_data *so_long, char *file)
{
	void	*img_ptr;
	int		width;
	int		height;

	img_ptr = mlx_png_file_to_image(so_long->mlx, file, &width, &height);
	if (img_ptr == NULL)
		p_error("Failed to load the object image.");
	return (img_ptr);
}

static void	set_object_images(t_data *so_long)
{
	so_long->map.objects.wall = get_png_image(so_long, "image/wall.png");
	so_long->map.objects.exit = get_png_image(so_long, "image/exit.png");
	so_long->map.objects.collect = get_png_image(so_long, "image/collect.png");
	so_long->map.objects.player = get_png_image(so_long, "image/player.png");
}

void	s_init_images(t_data *so_long)
{
	set_bg_image(so_long);
	set_object_images(so_long);
}
