/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:25:32 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:26 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

static int	is_valid_dict_line(char *line)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line;
	if (tmp[i] == '\n')
		return (1);
	if (!is_digit(tmp[i]))
		return (print_error_and_return_zero(1));
	while (is_digit(tmp[i]))
		i++;
	while (tmp[i] == ' ')
		i++;
	if (tmp[i] != ':')
		return (print_error_and_return_zero(1));
	i++;
	while (tmp[i] == ' ')
		i++;
	if (!is_printable(tmp[i]))
		return (print_error_and_return_zero(1));
	while (is_printable(tmp[i]))
		i++;
	if (tmp[i] != '\n')
		return (print_error_and_return_zero(1));
	return (1);
}

static int	is_valid_dict(int fd)
{
	char	*line;

	while (read_one_line(fd, &line))
	{
		if (!is_valid_dict_line(line))
		{
			free(line);
			return (0);
		}
		free(line);
	}
	if (*line)
	{
		if (!is_valid_dict_line(line))
		{
			free(line);
			return (0);
		}
	}
	free(line);
	return (1);
}

static int	is_valid_convert_value(char *to_convert)
{
	if (*to_convert == '-' || *to_convert == '+')
		to_convert++;
	if (is_only_digits(to_convert))
		return (1);
	print_error(0);
	return (0);
}

int	is_valid_arg(int ac, char *path, char *to_convert)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (ac >= 2 && ac <= 3 && fd != -1)
	{
		if (is_valid_convert_value(to_convert) && is_valid_dict(fd))
			if (!close(fd))
				return (1);
	}
	else
		print_error(0);
	close(fd);
	return (0);
}
