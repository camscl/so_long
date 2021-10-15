/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cafernan <cafernan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 19:09:46 by cafernan          #+#    #+#             */
/*   Updated: 2021/10/15 22:00:02 by cafernan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRUEBA_H
# define PRUEBA_H

#include <unistd.h>
#include <stdio.h>
#include <math.h>
#include "./minilibx/mlx.h"


# define WIN_WIDTH 500
# define WIN_HEIGHT 700

typedef struct  s_imag
{
    void    *img_ptr;
    int     *data;


    int 			size_l;
	int 			bpp;
	int 			endian;
} t_img;


typedef  struct 	s_mlx
{
	void 		* mlx_ptr;
	void 		* win;
	t_img img;
} t_mlx;







#endif