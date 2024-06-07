/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: awahmed <awaizahmed2005@gmail.com>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 21:29:12 by awahmed           #+#    #+#             */
/*   Updated: 2024/05/04 21:29:14 by awahmed          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_row(int x, char left, char mid, char right)
{
	int	i;

	i = 0;
	ft_putchar(left);
	while (i < x - 2)
	{
		ft_putchar(mid);
		i++;
	}
	if (x > 1)
		ft_putchar(right);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	print_row(x, 'A', 'B', 'C');
	while (i < y - 2)
	{
		print_row(x, 'B', ' ', 'B');
		i++;
	}
	if (y > 1)
		print_row(x, 'C', 'B', 'A');
}
