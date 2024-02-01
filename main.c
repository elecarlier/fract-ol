/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:27:59 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/01 18:10:42 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	main(int argc, char *argv[])
{
	t_fractal	fractal;
	if ((argc == 2 && !ft_strncmp(argv[1], "mandelbrot", 10))
		|| (argc == 4 && !ft_strncmp(argv[1], "julia", 5)))
	{
		fractal.name = argv[1];
		fractal_init(&fractal);
		fractal_render(&fractal);
		mlx_loop(fractal.mlx_ptr);

	}
	else
	{
		ft_printf("Please enter: \n\t./fractol mandelbrot\n");
		ft_printf("or \n\t./fractol julia <value1><value2>\n");

		exit(EXIT_FAILURE);
	}
}
