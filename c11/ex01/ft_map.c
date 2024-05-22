/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:16:17 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 13:51:14 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f) (int))
{
	int	i;
	int	*arr;

	arr = malloc(length * sizeof(int));
	i = -1;
	while (++i < length)
		arr[i] = f(tab[i]);
	return (arr);
}

// #include <stdio.h>
// int ft_dbl(int n)
// {
// 	return (n * 2);
// }

// int main()
// {
// 	int arr[] = {1,2,3,4,5,6,7,8,9};

// 	int *arr2 = ft_map(arr, 9, &ft_dbl);

// 	int i = 0;
// 	while (i < 9)
// 		printf("%i, ", arr2[i++]);
// }
