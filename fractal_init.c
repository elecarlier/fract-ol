/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractal_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 17:09:31 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/04 19:16:35 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	malloc_error(void)
{
	perror("Mallocing error\n");
	exit(EXIT_FAILURE);
}

void fractal_init(t_fractal *f)
{
	/*Need to create a function to clean exit */
	f->mlx_ptr = mlx_init();
	if (!f->mlx_ptr)
		malloc_error();
	f->win_ptr = mlx_new_window(f->mlx_ptr, WIDTH, HEIGHT, f->name);
	if (!f->win_ptr)
	{
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
		malloc_error();
	}
	f->img.img_ptr = mlx_new_image(f->mlx_ptr, WIDTH, HEIGHT);
	if (!f->img.img_ptr)
	{
		mlx_destroy_window(f->mlx_ptr, f->win_ptr);
		mlx_destroy_display(f->mlx_ptr);
		free(f->mlx_ptr);
		malloc_error();
	}

	f->img.pixels_ptr = mlx_get_data_addr(f->img.img_ptr, &f->img.bpp, &f->img.line_len, &f->img.endian);
	//events_init(f) //listen for events
	//data_init(f) //contain all the wooms, iterations, etccc
}

