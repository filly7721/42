/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:36:05 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/22 21:23:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	rec_putnbr(unsigned int nb)
{
	char	c;

	if (nb == 0)
		return ;
	c = nb % 10 + '0';
	rec_putnbr(nb / 10);
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb == 0)
		write(1, "0", 1);
	else if (nb < 0)
	{
		write(1, "-", 1);
		rec_putnbr(nb * -1);
	}
	else
		rec_putnbr(nb);
}
