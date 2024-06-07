/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awahmed <awaizahmed2005@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:29:06 by awahmed           #+#    #+#             */
/*   Updated: 2024/05/04 21:29:08 by awahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rush(int x, int y);

int	parse_int(char *str)
{
	int	val;
	int	i;

	val = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			return (-1);
		}
		val *= 10;
		val += str[i] - '0';
		i++;
	}
	return (val);
}

int	main(int argc, char *argv[])
{
	int	x;
	int	y;

	if (argc < 3)
	{
		write(2, "Invalid Dimensions\n", 19);
		return (-1);
	}
	x = parse_int(argv[1]);
	y = parse_int(argv[2]);
	if (x < 1 || y < 1)
	{
		write(2, "Invalid Dimensions\n", 19);
		return (-1);
	}
	rush(x, y);
	return (0);
}
