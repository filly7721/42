/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_foreach.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:14:33 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 13:15:58 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_foreach(int *tab, int length, void (*f)(int))
{
	int	i;

	i = 0;
	while (i < length)
		f(tab[i++]);
}

// #include <stdio.h>
// void ft_putnbr(int n)
// {
// 	printf("%i, ", n);
// }

// int main()
// {
// 	int arr[] = {1,2,3,4,5,6,7,8,9};

// 	ft_foreach(arr, 9, &ft_putnbr);
// }
