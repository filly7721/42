/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:20:40 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:33:58 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

void	fill_dict(int i, char *line, t_data *data)
{
	if (i <= 19)
		data->parsed_dict_20[i] = line;
	else if (i <= 100 && !(i % 10))
		data->parsed_dict_rest[(i - 20) / 10] = line;
	else if (i == 1000)
		data->parsed_dict_rest[T_INDEX] = line;
	else if (i == 1000000)
		data->parsed_dict_rest[M_INDEX] = line;
	else if (i == 1000000000)
		data->parsed_dict_rest[B_INDEX] = line;
}

int	parse(char *path, t_data *data)
{
	int		fd;
	long	i;
	char	*line;

	fd = open(path, O_RDONLY);
	if (fd == -1)
	{
		print_error(0);
		return (0);
	}
	while (read_one_line(fd, &line))
	{
		if (*line != '\n')
		{
			fill_dict(ft_atoi(line), strtrim(in_string(':', line) + 1), data);
			free(line);
		}
	}
	if (*line)
		free(line);
	i = -1;
	return (1);
}
