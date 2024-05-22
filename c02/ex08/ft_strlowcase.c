/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 23:03:21 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/03 23:03:24 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
		{
			str[i] += 'a' - 'A';
		}
		i++;
	}
	return (str);
}
// #include <stdio.h>
// int	main()
// {
// 	char str[] = "Hello World! how are we ALL? here are some symbols @!$`#{} ";
// 	ft_strlowcase(str);
// 	puts(str);
// }
