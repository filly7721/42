/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 14:48:57 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 20:42:14 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int	i;
	int	sorted;

	i = 0;
	sorted = 1;
	while (i < length - 1 && sorted)
	{
		if ((*f)(tab[i], tab [i + 1]) < 0)
			sorted = 0;
		i++;
	}
	if (sorted == 1)
		return (1);
	sorted = 1;
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
			return (0);
		i++;
	}
	return (1);
}

// #include <stdio.h>
//
// int	ft_strcmp(int s1, int s2)
// {
// 	return (s1 - s2);
// }
//
// int main()
// {
// 	int arr[] = {9,8,7,6,5,5,3,2,1};
//
// 	printf("%d", ft_is_sort(arr, 9, &ft_strcmp));
// }