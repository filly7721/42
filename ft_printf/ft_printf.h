/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:31:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 13:31:09 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H 

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int	ft_printf(const char *str, ...);
int	ft_putint(int n);
int	ft_putuint(unsigned int n);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putlhex(unsigned int num);
int	ft_putuhex(unsigned int num);
int	ft_putptr(void *ptr);

int	rec_putnbr(unsigned int num);

#endif
