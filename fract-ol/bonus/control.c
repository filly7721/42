/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:05:18 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:19 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	max(int a, int b)
{
	if (a < b)
		return (b);
	return (a);
}

int	keyboard_handler(int keycode, t_env *env)
{
	if (keycode == 0)
		env->camera.x += 0.1 * env->camera.zoom;
	else if (keycode == 2)
		env->camera.x -= 0.1 * env->camera.zoom;
	else if (keycode == 13)
		env->camera.y += 0.1 * env->camera.zoom;
	else if (keycode == 1)
		env->camera.y -= 0.1 * env->camera.zoom;
	else if (keycode == 14)
		env->iter += 10;
	else if (keycode == 12)
		env->iter = max(env->iter - 10, 0);
	else if (keycode == 53)
		free_exit(env);
	else if (keycode == 3)
		env->color++;
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	double	p[2];

	if (mousecode == 4)
	{
		p[0] = (double)x / WIN_SIZE * 4 - 2;
		env->camera.x -= 0.2 * env->camera.zoom * p[0];
		p[1] = (double)(WIN_SIZE - y - 1) / WIN_SIZE * 4 - 2;
		env->camera.y += 0.2 * env->camera.zoom * p[1];
		env->camera.zoom *= 0.8;
	}
	else if (mousecode == 5)
		env->camera.zoom /= 0.8;
	return (0);
}
