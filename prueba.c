/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:22:05 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/15 22:19:39 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prueba.h"

int main(void)
{
    t_mlx   mlx;
    int     count_w;
    int     count_h;

    count_h = -1;
    
    mlx.mlx_ptr = mlx_init();
    mlx.win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Esto es una prueba");

    mlx.img.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);

    mlx.img.data = (int *)mlx_get_data_addr(mlx.img.img_ptr, &mlx.img.bpp, &mlx.img.size_l,
		&mlx.img.endian);

    while (++count_h < WIN_HEIGHT)
	{
		count_w = -1;
		while (++count_w < WIN_WIDTH)
		{
			if (count_w % 2)
            mlx.img.data[count_h * WIN_WIDTH + count_w] = 0x00FF0000;
			else
				mlx.img.data[count_h * WIN_WIDTH + count_w] = 0;
		}
	}
    mlx_put_image_to_window(mlx.mlx_ptr, mlx.win, mlx.img.img_ptr, 0, 0);
	mlx_loop(mlx.mlx_ptr);


    return(0);
}