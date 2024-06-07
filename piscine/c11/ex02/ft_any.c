/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_any.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/21 13:54:01 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/21 14:22:14 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_any(char **tab, int (*f)(char *))
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (f(tab[i]) != 0)
			return (1);
		i++;
	}
	return (0);
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
// 	char* chs[4];

// 	char a = 'g';
// 	char b = 'b';
// 	char c = 'c';

// 	chs[0] = &a;
// 	chs[1] = &b;
// 	chs[2] = &c;
// 	chs[3] = 0;

// 	printf("%i, ",ft_any(chs, &ft_cmp));
// }
