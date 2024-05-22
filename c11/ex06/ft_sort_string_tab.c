/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 20:09:03 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 20:09:34 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

void	swap(char **str1, char **str2)
{
	char	*temp;

	temp = *str2;
	*str2 = *str1;
	*str1 = temp;
}

void	sort_str(char *tab[], int size)
{
	int	i;
	int	j;

	i = 1;
	while (i < size)
	{
		j = 1;
		while (j < size)
		{
			if (ft_strcmp(tab[j], tab[j - 1]) < 0)
				swap(&tab[j], &tab[j - 1]);
			j++;
		}
		i++;
	}
}

void	ft_sort_string_tab(char **tab)
{
	int	size;

	size = 0;
	while (tab[size] != NULL)
		size++;
	sort_str(tab, size);
}

// #include <stdio.h>
// int	main(int argc, char **argv)
// {
// 	char *strs[] = {"Hello", "World", "a","z", "A", "1", NULL};
// 	ft_sort_string_tab(strs);
// 	int i = 0;
// 	while(strs[i])
// 		printf("%s\n", strs[i++]);
// }
