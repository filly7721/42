/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 01:09:39 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/08 01:10:07 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	v;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	v = 1;
	while (power > 0)
	{
		v *= nb;
		power--;
	}
	return (v);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_iterative_power(2, 4));
// 	return 0;
// }