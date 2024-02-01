/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:34:01 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/01 18:09:58 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <X11/keysym.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"

#define WIDTH	800
#define	HEIGHT	800

typedef struct s_img
{
	void	*img_ptr; //ptr to image struct
	char	*pixels_ptr; //to the actual pixels
	int	bpp; //bit per pixel
	int	endian;
	int	line_len;
}				t_img;

typedef struct	s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
}				t_fractal;


#endif
