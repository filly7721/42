/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_div_mod.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 16:07:57 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/02 16:13:37 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_ultimate_div_mod(int *a, int *b)
{
	int	c;

	c = *a;
	*a = c / *b;
	*b = c % *b;
}
//int	main()
//{
//	int	a;
//	int	b;
//
//	a = 27;
//	b = 5;
//
//	ft_ultimate_div_mod(&a, &b);
//	printf("div:%d, mod:%d", a, b);
//}
