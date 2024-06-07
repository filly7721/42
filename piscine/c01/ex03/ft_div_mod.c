/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_div_mod.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 15:56:39 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/02 16:06:32 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <stdio.h>
void	ft_div_mod(int a, int b, int *div, int *mod)
{
	*div = a / b;
	*mod = a % b;
}
//int	main()
//{
//	int a;
//	int b;
//	int div;
//	int mod;
//
//	a = 17;
//	b = 3;
//
//	ft_div_mod(a, b, &div, &mod);
//	printf("a:%d, b:%d, div:%d, mod:%d", a, b, div, mod);
//}
