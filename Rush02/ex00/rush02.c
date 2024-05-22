/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:21:06 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:02 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	rush02(int ac, char **av)
{
	char	*path;
	char	*to_convert;
	t_data	data;

	if (!init_data(&data))
		return ;
	if (ac == 3)
	{
		path = av[1];
		to_convert = av[2];
	}
	else
	{
		path = FILE_PATH;
		to_convert = av[1];
	}
	if (is_valid_arg(ac, path, to_convert))
		if (parse(path, &data))
			if (convert(to_convert, &data))
				ft_putstrn(strtrim(data.res));
	ft_free(&data);
}
