/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   param.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:51:42 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/05 13:54:02 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	mandelbrot_param(t_fractal *f, char *name)
{
	f->name = name;
	f->iteration = 150;
	f->color = 0xccf1ff;

}


// typedef struct s_fractal
// {
// 	char	*name;
// 	void	*mlx_ptr;
// 	void	*win_ptr;
// 	t_img	img;
// 	int	iteration;
// 	int	color; //0xccf1ff


// }
