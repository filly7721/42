/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:06:12 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:06:13 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H

# include "mlx.h"
# include <unistd.h>
# include <stdlib.h>
# include <math.h>

# define WIN_SIZE 500
# define DEF_ITER 50

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_data;

typedef struct s_camera
{
	double	x;
	double	y;
	double	zoom;
}	t_camera;

typedef enum s_fractol
{
	MANDELBROT,
	JULIA
}	t_fractol;

typedef struct s_env
{
	void		*mlx;
	void		*win;
	t_data		data;
	t_camera	camera;
	t_fractol	fract;
	double		c[2];
	int			iter;
}	t_env;

int		mandel_brot(double p[2], t_env *env);
int		render(t_env *env);
int		keyboard_handler(int keycode, t_env *env);
int		mouse_handler(int mousecode, int x, int y, t_env *env);
int		julia(double p[2], double c[2], t_env *env);
double	ft_atof(char *str);
int		ft_strcmp(char *s1, char *s2);
int		free_exit(t_env *env);

#endif
