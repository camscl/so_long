/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:25:27 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	struct_init(t_data *so_long)
{
	so_long->win_width = MAP_TILE_SIZE * so_long->map.width;
	so_long->win_height = MAP_TILE_SIZE * so_long->map.height;
	so_long->state.player_pos = player_position(&(so_long->map));
	so_long->state.remaining_collect = s_count_collects(&(so_long->map));
	so_long->state.move_count = 0;
	so_long->state.is_gameend = FT_FALSE;
}

void	start_solong(char *map_name)
{
    t_data  so_long;
    p_map(map_name, &so_long);
    struct_init(&so_long);
    so_long.mlx = mlx_init();
	so_long.win = mlx_new_window(so_long.mlx, \
		so_long.win_width, so_long.win_height, "So Long");
	s_init_images(&so_long);
	s_draw_frame(&so_long);
	mlx_key_hook(so_long.win, &skey_hook, &so_long);
	mlx_hook(so_long.win, CLOSE_BUTTON, 0, &s_exit_button, &so_long);
	mlx_loop(so_long.mlx);
}

int main(int argc, char **argv)
{
    if(argc == 2)
        start_solong(argv[1]);
    else
        p_error("argumentos insuficientes");
    return(0);
        
}