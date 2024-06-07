/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:21:59 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:09 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putstrn(char *str)
{
	ft_putstr(str);
	ft_putstr("\n");
}

void	print_error(int err)
{
	if (err == 1)
		ft_putstrn(ERR_NO_1);
	else
		ft_putstrn(ERR_NO_0);
}

char	*in_string(char c, char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (&str[i]);
		i++;
	}
	return (str);
}

int	init_data(t_data *data)
{
	int	i;

	i = -1;
	data->res = malloc(sizeof(char) * 1);
	data->parsed_dict_20 = malloc(sizeof(char *) * (DICT_SIZE + 1));
	data->parsed_dict_rest = malloc(sizeof(char *) * (DICT_SIZE + 1));
	if (!data->res || !data->parsed_dict_20 || !data->parsed_dict_rest)
	{
		print_error(0);
		return (0);
	}
	data->res[0] = '\0';
	while (++i <= DICT_SIZE)
	{
		data->parsed_dict_20[i] = NULL;
		data->parsed_dict_rest[i] = NULL;
	}
	return (1);
}
