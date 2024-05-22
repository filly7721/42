/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:19:19 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/11 20:36:55 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	if (max <= min)
	{
		*range = NULL;
		return (0);
	}
	size = max - min;
	arr = malloc(size * sizeof(int));
	if (arr == NULL)
		return (-1);
	i = -1;
	while (++i < size)
		arr[i] = min + i;
	*range = arr;
	return (i);
}

// #include <stdio.h>
// int main()
// {
// 	const int min = 0;
// 	const int max = 10;
// 	int *arr;
// 	const int size = ft_ultimate_range(&arr, min, max);
//
// 	int i = 0;
// 	while(i < size)
// 	{
// 		printf("%d", arr[i]);
// 		i++;
// 	}
// }