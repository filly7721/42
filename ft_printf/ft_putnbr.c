/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:17:23 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/26 08:17:26 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_putnbr(unsigned int n)
{
	int		count;

	if (n < 10)
		return (ft_putchar(n + '0'));
	count = rec_putnbr(n / 10);
	if (count < 0)
		return (-1);
	if (ft_putchar(n % 10 + '0') < 0)
		return (-1);
	return (count + 1);
}

int	ft_putint(int n)
{
	int	count;

	count = 0;
	if (n >= 0)
		return (rec_putnbr(n));
	if (ft_putchar('-') < 0)
		return (-1);
	count = rec_putnbr(-n);
	if (count < 0)
		return (-1);
	return (1 + count);
}

int	ft_putuint(unsigned int n)
{
	return (rec_putnbr(n));
}
