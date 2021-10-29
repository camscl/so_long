/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camscl <camscl@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/29 18:24:02 by camscl           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"


static void	smove_up(t_data *so_long)
{
	t_point	pos_to_move;

	pos_to_move.xpos = so_long->state.player_pos.xpos;
	pos_to_move.ypos = so_long->state.player_pos.ypos - 1;
	if (ispossible_move(so_long, pos_to_move) == FT_FALSE)
		return ;
	if (so_long->state.is_gameend == FT_TRUE)
		s_the_end(so_long);
	so_long->state.player_pos.ypos--;
	so_long->state.move_count++;
}

static void	smove_down(t_data *so_long)
{
	t_point	pos_to_move;

	pos_to_move.xpos = so_long->state.player_pos.xpos;
	pos_to_move.ypos = so_long->state.player_pos.ypos + 1;
	if (ispossible_move(so_long, pos_to_move) == FT_FALSE)
		return ;
	if (so_long->state.is_gameend == FT_TRUE)
		s_the_end(so_long);
	so_long->state.player_pos.ypos++;
	so_long->state.move_count++;
}

static void	smove_left(t_data *so_long)
{
	t_point	pos_to_move;

	pos_to_move.xpos = so_long->state.player_pos.xpos - 1;
	pos_to_move.ypos = so_long->state.player_pos.ypos;
	if (ispossible_move(so_long, pos_to_move) == FT_FALSE)
		return ;
	if (so_long->state.is_gameend == FT_TRUE)
		s_the_end(so_long);
	so_long->state.player_pos.xpos--;
	so_long->state.move_count++;
}

static void	smove_right(t_data *so_long)
{
	t_point	pos_to_move;

	pos_to_move.xpos = so_long->state.player_pos.xpos + 1;
	pos_to_move.ypos = so_long->state.player_pos.ypos;
	if (ispossible_move(so_long, pos_to_move) == FT_FALSE)
		return ;
	if (so_long->state.is_gameend == FT_TRUE)
		s_the_end(so_long);
	so_long->state.player_pos.xpos++;
	so_long->state.move_count++;
}


int	skey_hook(int keycode, t_data *so_long)
{
	if (keycode == KEY_W || keycode == KEY_ARROW_UP)
		smove_up(so_long);
	else if (keycode == KEY_S || keycode == KEY_ARROW_DOWN)
		smove_down(so_long);
	else if (keycode == KEY_A || keycode == KEY_ARROW_LEFT)
		smove_left(so_long);
	else if (keycode == KEY_D || keycode == KEY_ARROW_RIGHT)
		smove_right(so_long);
	else if (keycode == KEY_ESC || keycode == KEY_Q)
		s_exit(so_long);
	s_draw_frame(so_long);
	//so_long_print_counter(so_long);
	return (0);
}

