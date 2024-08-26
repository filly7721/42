/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:05:49 by ashalaab          #+#    #+#             */
/*   Updated: 2024/08/08 19:05:50 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

double	ft_atof(char *str)
{
	double	whole;
	double	dec;
	double	sign;
	int		i;
	int		j;

	whole = 0;
	dec = 0;
	i = 0;
	while (str[i] == ' ')
		i++;
	sign = 1;
	if (str[i] == '-' || str[i] == '+')
		if (str[i++] == '-')
			sign = -1;
	while (str[i] >= '0' && str[i] <= '9')
		whole = whole * 10 + str[i++] - '0';
	if (str[i++] != '.')
		return (sign * whole);
	j = i;
	while (str[i] >= '0' && str[i] <= '9')
		dec = dec * 10 + str[i++] - '0';
	while (i-- > j)
		dec /= 10;
	return (sign * (whole + dec));
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s2[i] - (unsigned char)s1[i]);
}
