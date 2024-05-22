/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/08 20:10:17 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/09 10:17:20 by ashalaab         ###   ########.fr       */
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

	i = 2;
	while (i < size)
	{
		j = 2;
		while (j < size)
		{
			if (ft_strcmp(tab[j], tab[j - 1]) < 0)
			{
				swap(&tab[j], &tab[j - 1]);
			}
			j++;
		}
		i++;
	}
}

void	pt_str(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	write(1, str, i);
	write(1, "\n", 1);
}

int	main(int argc, char *argv[])
{
	int	i;

	sort_str(argv, argc);
	i = 1;
	while (i < argc)
		pt_str(argv[i++]);
	return (0);
}
