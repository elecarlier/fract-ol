/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:31 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/01 18:30:45 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void init(t_fractal *f)
{
	/*Need to create a function to clean exit */
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		return (1);
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->name);
	if (!f->win_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
		return (1);
	}
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
		return (1);
	}
	//img data
}

