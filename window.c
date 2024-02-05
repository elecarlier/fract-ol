/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 17:43:02 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/04 15:47:05 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

#define MLX_ERROR	1
#define WIDTH			400
#define HEIGHT			400

typedef struct	s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
}				t_mlx;

int	key_hook(int keysym, t_mlx *vars)
{

	if (keysym == XK_Escape)
	{
		printf("The %d key (ESC) has been pressed\n\n", keysym);
		mlx_destroy_window(vars->mlx_ptr, vars->win_ptr);
		mlx_destroy_display(vars->mlx_ptr);
		free(vars->mlx_ptr);
		exit(1);
	}
	printf("The %d key has been pressed\n\n", keysym);
	return (0);
}

// int mouse_hook(int keysym, t_mlx *vars)
// {

// }

int	main(void)
{
	t_mlx vars;

	vars.mlx_ptr = mlx_init(); //have to free
	if (!vars.mlx_ptr)
		return (1);

	vars.win_ptr = mlx_new_window(vars.mlx_ptr, WIDTH, HEIGHT, "Hello world!");
	if (!vars.win_ptr)
	{
		mlx_destroy_display(vars.mlx_ptr);
		free(vars.mlx_ptr);
		return (MLX_ERROR);
	}

	mlx_key_hook(vars.win_ptr, key_hook, &vars);
	//mlx_mouse_hook(vars.win_ptr, mouse_hook, &vars);

	//mlx_loop_hook(mlx, render_next_frame, YourStruct);
	mlx_loop(vars.mlx_ptr);

}

