/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 19:24:57 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/11 19:46:35 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	size;
	int	i;
	int	*arr;

	if (max <= min)
		return (NULL);
	size = max - min;
	arr = malloc(size * sizeof(int));
	i = 0;
	while (i < size)
	{
		arr[i] = min + i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int main()
// {
// 	const int min = 0;
// 	const int max = 10;
// 	int *arr = ft_range(min, max);

// 	int i = 0;
// 	while(i < max - min)
// 	{
// 		printf("%d", arr[i]);
// 		i++;
// 	}
// }