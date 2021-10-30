/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_tates.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/31 00:06:29 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	s_destroy_images(t_data *so_long)
{
	mlx_destroy_image(so_long->mlx, so_long->map.objects.wall);
	mlx_destroy_image(so_long->mlx, so_long->map.objects.exit);
	mlx_destroy_image(so_long->mlx, so_long->map.objects.collect);
	mlx_destroy_image(so_long->mlx, so_long->map.objects.player);
}

void	s_exit(t_data *so_long)
{
	mlx_destroy_window(so_long->mlx, so_long->win);
	s_destroy_images(so_long);
	ft_lstclear(&(so_long->map.raw), free);
	free(so_long->map.array);
	print_a_message("Exit. So Long!");
	exit(EXIT_SUCCESS);
}

int	s_exit_button(t_data *so_long)
{
	s_exit(so_long);
	return (FT_SUCCESS);
}

void	s_the_end(t_data *so_long)
{
	ft_putstr_fd(BLUE, STDIN_FILENO);
	print_a_message("Game End.");
	ft_putstr_fd(RESET, STDIN_FILENO);
	s_exit(so_long);
}
