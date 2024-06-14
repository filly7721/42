/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:31:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 13:31:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	rec_putnbr(unsigned int num)
{
	int	i;

	if (num <= 0)
		return (0);
	i = rec_putnbr(num / 10);
	ft_putchar(num % 10 + '0');
	return (i + 1);
}

int	ft_putuint(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		i += ft_putchar('0');
	else
		i += rec_putnbr(n);
	return (i);
}

int	ft_putint(int n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		i += ft_putchar('-');
		i += ft_putuint(-n);
	}
	else
		i += ft_putuint(n);
	return (i);
}
