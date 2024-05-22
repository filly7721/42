/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:21:50 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:07 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

int	is_space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	is_digit(char c)
{
	return (c >= 48 && c <= 57);
}

int	is_printable(char c)
{
	return (c >= 32 && c <= 126);
}

int	is_only_digits(char *str)
{
	while (*str)
		if (!is_digit(*str++))
			return (0);
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}
