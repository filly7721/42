/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:25:14 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:22 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*get_string_type(int num)
{
	if (num == THOUSAND)
		return ("thousand");
	else if (num == MILLION)
		return ("million");
	else if (num == BILLION)
		return ("billion");
	else if (num == HUNDRED)
		return ("hundred");
	else
		return ("");
}

int	print_error_and_return_zero(int err_msg)
{
	print_error(err_msg);
	return (0);
}

long	check_for_minus(long num, t_data *data)
{
	if (num < 0)
	{
		num = -num;
		add_to_res("minus", data);
	}
	return (num);
}

int	add_to_res(char *val, t_data *data)
{
	char	*tmp;

	tmp = data->res;
	data->res = ft_strjoin(data->res, val);
	free(tmp);
	tmp = data->res;
	data->res = ft_strjoin(data->res, " ");
	free(tmp);
	return (1);
}

void	ft_free(t_data *data)
{
	int	i;

	i = 0;
	while (i < DICT_SIZE - 1)
	{
		if (data->parsed_dict_20[i])
			free(data->parsed_dict_20[i]);
		if (data->parsed_dict_rest[i])
			free(data->parsed_dict_rest[i]);
		i++;
	}
	if (data->res)
		free(data->res);
}
