/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 00:52:12 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/08 01:12:47 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_sqrt(int nb)
{
	int		min;
	int		max;
	long	n;

	if (nb < 1)
		return (0);
	min = 1;
	max = nb;
	while (max >= min)
	{
		n = (min + max) / 2;
		if (n * n == nb)
			return (n);
		else if (n * n > nb)
			max = n - 1;
		else if (n * n < nb)
			min = n + 1;
	}
	return (0);
}

// #include <stdio.h>
// int main()
// {
// 	printf("%d", ft_sqrt(4));
// 	return 0;
// }