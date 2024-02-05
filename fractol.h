/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 16:34:01 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/05 13:54:19 by ecarlier         ###   ########.fr       */
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

# define WIDTH	800
# define HEIGHT	800


#define BLACK       0x000000  // RGB(0, 0, 0)
#define WHITE       0xFFFFFF  // RGB(255, 255, 255)
#define SUNSET_ORANGE       0xFF4500    // Orange coucher de soleil
#define COSMIC_PURPLE       0x6F00FF    // Violet cosmique
#define ELECTRIC_GREEN      0x00FF7F    // Vert électrique
#define TURQUOISE_BLUE      0x00CED1    // Bleu turquoise
#define VIOLET_FLAME        0x8A2BE2    // Flamme violette
#define GOLDENROD_YELLOW    0xDAA520    // Jaune tige
#define RASPBERRY_PINK      0xE30B5C    // Rose framboise
#define TANGERINE_ORANGE    0xFFA500    // Orange mandarine
#define AMETHYST_PURPLE     0x9966CC    // Violet améthyste
#define JADE_GREEN          0x00A86B    // Vert jade
#define INDIGO_BLUE         0x4B0082    // Bleu indigo
#define SCARLET_RED         0xFF2400    // Rouge écarlate
#define TURQUOISE_GREEN     0xA0D6B4    // Vert turquoise
#define AZURE_BLUE          0x007FFF    // Bleu azur
#define CITRUS_YELLOW       0xF8DE7E    // Jaune citron
#define LILAC_PURPLE        0xC8A2C8    // Violet lilas
#define CITRINE_YELLOW      0xE4D00A    // Jaune citrine
#define PEACH_ORANGE        0xFFDAB9    // Orange pêche
#define TEAL_BLUE           0x367588    // Bleu sarcelle
#define COBALT_BLUE         0x0047AB    // Bleu cobalt

typedef struct s_img
{
	void	*img_ptr; //ptr to image struct
	char	*pixels_ptr; //to the actual pixels
	int	bpp; //bit per pixel
	int	endian; //ensures system portability
	int	line_len; //lenght of *pixel_ptr


}				t_img;

typedef struct s_fractal
{
	char	*name;
	void	*mlx_ptr;
	void	*win_ptr;
	t_img	img;
	int	iteration;
	int	color; //0xccf1ff


}				t_fractal;

typedef struct s_pos
{
	int	x;
	int	y;
}				t_pos;

// typedef struct s_scale
// {
// 	double	old_max;
// 	double	old_min;
// 	double	new_max;
// 	double	new_min;
// }				t_scale;


typedef struct s_complex
{
	double	x;
	double	y;
}				t_complex;


//render

void	fractal_render(t_fractal *f);
//fractal_init
void	fractal_init(t_fractal *f);

//math_utils
double	scaling(double unscaled_num, double new_min,
			double new_max, double old_max);
t_complex	sum_complex(t_complex a, t_complex b);
t_complex	to_p_2(t_complex n);


//param
void	mandelbrot_param(t_fractal *f, char *name);
#endif
