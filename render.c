/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 16:09:03 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/05 14:02:29 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static void	my_pixel_put(int x, int y, t_img *img, int color)
{
	int	offset;

	offset = (y * img->line_len) + (x * (img->bpp / 8));
	*(unsigned int *)(img->pixels_ptr + offset) = color;
}
/*
	MANDELBROT
	z = z^2 + c
	z is (0.0)
	c is the point that we want to check
*/
static void handle_pixel(int x, int y, t_fractal *f)
{
	t_complex z;
	t_complex c;
	int i;
	int color;

	i = 0;

	//first iter
	z.x = 0.0;
	z.y = 0.0;

	//scale
	c.x = scaling(x, -2, +2, WIDTH); //(x, -2, +2, 0, WIDTH) 0 pour old min
	c.y = scaling(y, +2, -2, HEIGHT);

	// les autres iterations
	 while (i++ < f->iteration )
	{
		z = sum_complex(to_p_2(z), c);

		//if diverge to infinity /!\ si l'hypotenuse > 2, on suppose que le point  fuit
		// 4  = f.escaped_value
		if ((z.x * z.x) + (z.y * z.y) > 4)
		{
			color = scaling(i, BLACK, WHITE, f->iteration);
			my_pixel_put(x, y, &f->img, color);
			return;
		}
		//means that we are in mandelbrot set
		my_pixel_put(x, y, &f->img, RASPBERRY_PINK);
	}


}

/*	On commence tout en haut 0.0 et on traite chaque pixel avec handle_pixel
	comme une matrice. Le but est de "scale"
	----- x ----
	[          ] |
	[          ] |
	[          ] y
	[          ] |
	[          ] | (height, widht)
	*/
void	fractal_render(t_fractal *f)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			handle_pixel(x, y, f);
		}
	}
	mlx_put_image_to_window(f->mlx_ptr, f->win_ptr, f->img.img_ptr, 0, 0);
}
