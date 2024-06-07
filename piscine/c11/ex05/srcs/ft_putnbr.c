/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:24:37 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 20:24:38 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

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
	if (nb < 0)
	{
		write(1, "-", 1);
		rec_putnbr(nb * -1);
	}
	else
		rec_putnbr(nb);
}
