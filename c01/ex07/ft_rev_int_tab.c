/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/02 17:31:09 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/02 22:28:03 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//#include <unistd.h>
void	ft_rev_int_tab(int *tab, int size)
{
	int	max;
	int	i;
	int	temp;

	if (size == 0)
		return ;
	i = 0;
	max = (size - 1) / 2;
	while (i <= max)
	{
		temp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = temp;
		i++;
	}
}

//int main()
//{
//	int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
//	ft_rev_int_tab(arr, 9);
//	int i = 0;
//	char c;
//	while (i < 9)
//	{
//		c = '0' + arr[i];
//		write(1,&c,1);
//		i++;
//	}
//}
