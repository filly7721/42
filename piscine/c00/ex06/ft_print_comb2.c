/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 22:04:31 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/01 22:48:31 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(int num1, int num2)
{
	char	char1;
	char	char2;
	char	char3;
	char	char4;

	char1 = '0' + (num1 / 10) % 10;
	char2 = '0' + num1 % 10;
	char3 = '0' + (num2 / 10) % 10;
	char4 = '0' + num2 % 10;
	write(1, &char1, 1);
	write(1, &char2, 1);
	write(1, " ", 1);
	write(1, &char3, 1);
	write(1, &char4, 1);
	if (num1 != 98)
		write(1, ", ", 2);
}

void	ft_print_comb2(void)
{
	int	num1;
	int	num2;

	num1 = 0;
	while (num1 < 100)
	{
		num2 = num1 + 1;
		while (num2 < 100)
		{
			print_numbers(num1, num2);
			num2++;
		}
		num1++;
	}
}

//int	main()
//{
//	ft_print_comb2();
//}
