/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 09:00:44 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/09 09:31:26 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (tab[j] < tab[j - 1])
			{
				temp = tab[j];
				tab[j] = tab[j - 1];
				tab[j - 1] = temp;
			}
			j++;
		}
		i++;
	}
}

// #include <stdio.h>
// int main()
// {
// 	int arr[] = {10, 5, 90, 44, 27, 1};
// 	ft_sort_int_tab(arr, 6);

// 	int i = 0;

// 	while (i < 6){
// 		printf("%i, ", arr[i++]);
// 	}
// }