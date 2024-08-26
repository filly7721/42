/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:06:01 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:06:02 by ashalaab         ###   ########.fr       */
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
	if (keycode == 14)
		env->iter += 10;
	else if (keycode == 12)
		env->iter = max(env->iter - 10, 0);
	else if (keycode == 53)
		free_exit(env);
	return (0);
}

int	mouse_handler(int mousecode, int x, int y, t_env *env)
{
	(void)x;
	(void)y;
	if (mousecode == 4)
		env->camera.zoom *= 0.8;
	else if (mousecode == 5)
		env->camera.zoom /= 0.8;
	return (0);
}
