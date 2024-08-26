/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:05:42 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:43 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

void	translate_pixel(int p[2], double z[2], t_env *env)
{
	z[0] = 0;
	z[0] = (double)p[0] / WIN_SIZE * 4 - 2;
	z[0] *= env->camera.zoom;
	z[0] -= env->camera.x;
	z[1] = 0;
	z[1] = (double)(WIN_SIZE - p[1] - 1) / WIN_SIZE * 4 - 2;
	z[1] *= env->camera.zoom;
	z[1] += env->camera.y;
}

int	render(t_env *env)
{
	int		color;
	int		p[2];
	double	z[2];

	p[0] = 0;
	while (p[0] < WIN_SIZE)
	{
		p[1] = 0;
		while (p[1] < WIN_SIZE)
		{
			translate_pixel(p, z, env);
			if (env->fract == MANDELBROT)
				color = mandel_brot(z, env);
			else if (env->fract == JULIA)
				color = julia(z, env->c, env);
			else if (env->fract == SHIP)
				color = burning_ship(z, env);
			pixel_put(&env->data, p[0], p[1], color);
			p[1]++;
		}
		p[0]++;
	}
	mlx_put_image_to_window(env->mlx, env->win, env->data.img, 0, 0);
	return (1);
}
