/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pr_shell.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 20:13:42 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	print_counter(t_data *so_long)
{
	ft_putstr_fd("<Move counter>: ", STDIN_FILENO);
	ft_putnbr_fd(so_long->state.move_count, STDIN_FILENO);
	ft_putstr_fd("\n", STDIN_FILENO);
}

void print_a_message(char *message)
{
    ft_putstr_fd("<SYSTEM>",STDIN_FILENO);
    ft_putstr_fd(message, STDIN_FILENO);
    ft_putstr_fd("\n", STDIN_FILENO);
}


void	print_map_array(t_map *map)
{
	int		x;
	int		y;

	y = 0;
	while (y < map->height)
	{
		x = 0;
		while (x < map->width)
		{
			ft_putchar_fd(map->array[y][x], STDIN_FILENO);
			ft_putchar_fd(' ', STDIN_FILENO);
			x++;
		}
		ft_putchar_fd('\n', STDIN_FILENO);
		y++;
	}
}

int p_error(char *message)
{
    ft_putstr_fd(RED, STDIN_FILENO);
	ft_putstr_fd("<ERROR> ", STDIN_FILENO);
	ft_putstr_fd(message, STDIN_FILENO);
	ft_putstr_fd("\n", STDIN_FILENO);
	ft_putstr_fd(RESET, STDIN_FILENO);
	exit(EXIT_FAILURE);
}