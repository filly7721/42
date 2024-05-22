/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/01 20:23:26 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/01 21:41:50 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	print_numbers(char digit_1, char digit_2, char digit_3)
{
	write(1, &digit_1, 1);
	write(1, &digit_2, 1);
	write(1, &digit_3, 1);
	if (digit_1 != '7')
		write(1, ", ", 2);
}

void	ft_print_comb(void)
{
	char	digit_1;
	char	digit_2;
	char	digit_3;

	digit_1 = '0';
	while (digit_1 <= '9')
	{
		digit_2 = digit_1 + 1;
		while (digit_2 <= '9')
		{
			digit_3 = digit_2 + 1;
			while (digit_3 <= '9')
			{
				print_numbers(digit_1, digit_2, digit_3);
				digit_3++;
			}
			digit_2++;
		}
		digit_1++;
	}
}

//int main(){
//ft_print_comb();
//}
