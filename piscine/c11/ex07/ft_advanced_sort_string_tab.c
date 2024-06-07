/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:09:23 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 20:09:24 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str2;
	*str2 = *str1;
	*str1 = temp;
}

void	sort_str(char *tab[], int size, int (*cmp)(char *, char *))
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (cmp(tab[j], tab[j - 1]) < 0)
				swap(&tab[j], &tab[j - 1]);
			j++;
		}
		i++;
	}
}

void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int	size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	sort_str(tab, size, cmp);
}

// int	ft_strcmp(char *s1, char *s2)
// {
// 	int	i;
//
// 	i = 0;
// 	while (s1[i] != '\0' && s2[i] != '\0')
// 	{
// 		if (s1[i] != s2[i])
// 			return (s1[i] - s2[i]);
// 		i++;
// 	}
// 	return (s1[i] - s2[i]);
// }
//
// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char *strs[] = {"Hello", "World", "a","z", "A", "1", NULL};
// 	ft_advanced_sort_string_tab(strs, &ft_strcmp);
// 	int i = 0;
// 	while(strs[i])
// 		printf("%s\n", strs[i++]);
// }
