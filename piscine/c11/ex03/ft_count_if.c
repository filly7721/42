/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_if.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:54:01 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 14:46:59 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_count_if(char **tab, int length, int (*f)(char*))
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (tab[i] && i < length)
	{
		if (f(tab[i]) != 0)
			count++;
		i++;
	}
	return (count);
}

// #include <stdio.h>
// int ft_cmp(char *c)
// {
// 	if (*c == 'a')
// 		return 1;
// 	return 0;
// }

// int main()
// {
// 	char* chs[7];

// 	char a = 'a';
// 	char b = 'b';
// 	char c = 'c';

// 	chs[0] = &a;
// 	chs[1] = &b;
// 	chs[2] = &c;
// 	chs[3] = &a;
// 	chs[4] = &b;
// 	chs[5] = &c;
// 	chs[6] = 0;

// 	printf("%i",ft_count_if(chs, 7, &ft_cmp));
// }
