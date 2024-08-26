/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:06:08 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:06:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	complex_square(double *r, double *i)
{
	double	temp;

	temp = *r;
	*r = *r * *r - *i * *i;
	*i = 2 * *i * temp;
}

int	mandel_brot(double p[2], t_env *env)
{
	int		i;
	double	z[2];

	z[0] = p[0];
	z[1] = p[1];
	i = 1;
	while (i < env->iter && z[0] * z[0] + z[1] * z[1] < 4)
	{
		complex_square(&z[0], &z[1]);
		z[0] += p[0];
		z[1] += p[1];
		i++;
	}
	if (i == env->iter)
		return (0);
	return (i * 0x00DD00EE & 0x00ffffff);
}

int	julia(double p[2], double c[2], t_env *env)
{
	int		i;
	double	z[2];

	z[0] = p[0];
	z[1] = p[1];
	i = 1;
	while (i < env->iter && z[0] * z[0] + z[1] * z[1] < 4)
	{
		complex_square(&z[0], &z[1]);
		z[0] += c[0];
		z[1] += c[1];
		i++;
	}
	if (i == env->iter)
		return (0);
	return (i * 0x00DD00EE & 0x00ffffff);
}
