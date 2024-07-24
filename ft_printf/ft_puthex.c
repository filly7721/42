/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/26 08:17:18 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/26 08:17:21 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	rec_puthex(unsigned long long n, const char *lookup)
{
	int	count;

	if (n < 16)
		return (ft_putchar(lookup[n]));
	count = rec_puthex(n / 16, lookup);
	if (count < 0)
		return (-1);
	if (ft_putchar(lookup[n % 16]) < 0)
		return (-1);
	return (count + 1);
}

int	ft_putlhex(unsigned int n)
{
	return (rec_puthex(n, "0123456789abcdef"));
}

int	ft_putuhex(unsigned int n)
{
	return (rec_puthex(n, "0123456789ABCDEF"));
}

int	ft_putptr(void *ptr)
{
	int	i;

	if (ft_putstr("0x") < 0)
		return (-1);
	i = rec_puthex((unsigned long long) ptr, "0123456789abcdef");
	if (i < 0)
		return (-1);
	return (2 + i);
}
