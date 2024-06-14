/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:31:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 13:31:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (unsigned char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (c == '\0')
		return ((char *)&s[i]);
	return (0);
}

int	print_arg(char type, va_list args)
{
	if (type == 'c')
		return (ft_putchar(va_arg(args, int)));
	if (type == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (type == 'p')
		return (ft_putptr(va_arg(args, void *)));
	if (type == 'd' || type == 'i')
		return (ft_putint(va_arg(args, int)));
	if (type == 'u')
		return (ft_putuint(va_arg(args, unsigned int)));
	if (type == 'x')
		return (ft_putlhex(va_arg(args, unsigned int)));
	if (type == 'X')
		return (ft_putuhex(va_arg(args, unsigned int)));
	if (type == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *str, ...)
{
	int			i;
	int			count;
	va_list		args;

	va_start(args, str);
	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			count += print_arg(str[i], args);
		}
		else
			count += ft_putchar(str[i]);
		i++;
	}
	return (count);
}
