/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:06:16 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:06:17 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int	parse_args(char **args, int count, t_env *env)
{
	if (ft_strcmp(args[0], "mandelbrot") == 0)
	{
		env->fract = MANDELBROT;
		return (1);
	}
	else if (ft_strcmp(args[0], "julia") == 0 && count == 3)
	{
		env->fract = JULIA;
		env->c[0] = ft_atof(args[1]);
		env->c[1] = ft_atof(args[2]);
		return (1);
	}
	return (0);
}

static void	print_usage(void)
{
	char	*str;
	int		i;

	str = "usage: \n\
	./fractol mandelbrot\n\
	./fractol julia <real> <imaginary>\n";
	i = 0;
	while (str[i])
		i++;
	write(2, str, i);
}

int	free_exit(t_env *env)
{
	mlx_clear_window(env->mlx, env->win);
	mlx_destroy_image(env->mlx, env->data.img);
	mlx_destroy_window(env->mlx, env->win);
	free(env->mlx);
	exit (0);
}

int	main(int ac, char **av)
{
	t_env	env;

	if (ac < 2)
		return (print_usage(), 1);
	if (!parse_args(av + 1, ac - 1, &env))
		return (print_usage(), 1);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_SIZE, WIN_SIZE, "Hello world!");
	env.data.img = mlx_new_image(env.mlx, WIN_SIZE, WIN_SIZE);
	env.data.addr = mlx_get_data_addr(env.data.img,
			&env.data.bits_per_pixel, &env.data.line_length, &env.data.endian);
	env.camera.x = 0;
	env.camera.y = 0;
	env.camera.zoom = 1;
	env.iter = DEF_ITER;
	mlx_key_hook(env.win, keyboard_handler, &env);
	mlx_mouse_hook(env.win, mouse_handler, &env);
	mlx_hook(env.win, 17, 1L << 0, free_exit, &env);
	mlx_loop_hook(env.mlx, render, &env);
	mlx_loop(env.mlx);
}
