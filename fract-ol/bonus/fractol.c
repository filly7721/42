/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:05:28 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:29 by ashalaab         ###   ########.fr       */
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

int	get_color(t_env *env)
{
	env->color %= 3;
	if (env->color == 0)
		return (0x00DD00EE);
	else if (env->color == 1)
		return (0x003030a);
	else
		return (0x0030a0a ^ 0x00FFFFFF);
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
	return (i * get_color(env) & 0x00ffffff);
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
	return (i * get_color(env) & 0x00ffffff);
}

int	burning_ship(double p[2], t_env *env)
{
	int		i;
	double	z[2];
	double	fz[2];

	p[1] = -p[1];
	z[0] = p[0];
	z[1] = p[1];
	i = 1;
	while (i < env->iter && z[0] * z[0] + z[1] * z[1] < 4)
	{
		fz[0] = z[0] * z[0] - z[1] * z[1] + p[0];
		fz[1] = 2.0 * fabs(z[0]) * fabs(z[1]) + p[1];
		z[0] = fz[0];
		z[1] = fz[1];
		i++;
	}
	return (i * get_color(env) & 0x00ffffff);
}
