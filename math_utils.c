/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarlier <ecarlier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 18:44:28 by ecarlier          #+#    #+#             */
/*   Updated: 2024/02/04 19:03:36 by ecarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

/* formule de mise a l'echelle lineaire ,
	/!\ trop d'arguments -> norminette
	double unscaled_num, double new_min,
	double new_max, double old_min, double old_max)
	old min = 0

		return ((new_max - new_min) * (unscaled_num - old_min)
		/ (old_max - old_min) + new_min);
	*/
double	scaling(double unscaled_num, double new_min,
	double new_max, double old_max)
{
	return ((new_max - new_min) * (unscaled_num - 0)
		/ (old_max - 0) + new_min);
}

/*(a+bi) + (c+di) = (a+c) + (b+d)i*/

t_complex	sum_complex(t_complex a, t_complex b)
{
	t_complex	s;

	s.x = a.x + b.x;
	s.y = a.y + b.y;
	return (s);
}

/* (a+bi)^2 = a^2 +2abi - b^2
			= (a^2 - b^2) + 2abi */

t_complex	to_p_2(t_complex n)
{
	t_complex	r;

	r.x = (n.x * n.x) - (n.y * n.y);
	r.y = 2 * n.x * n.y;
	return (r);
}
