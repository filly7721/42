/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:46:18 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/04 19:59:31 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n && s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (i == n)
		return (0);
	return (s1[i] - s2[i]);
}
// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_strncmp("Hello", "Hello", 5));
// 	printf("%d\n", ft_strncmp("Hello World", "Hello World", 5));
// 	printf("%d\n", ft_strncmp("Hello World", "Hello There", 5));
// 	printf("\n");
// 	printf("%d\n", ft_strncmp("Hello World", "Hello There", 10));
// 	printf("%d\n", ft_strncmp("Hello There", "Hello World", 10));
// 	printf("\n");
// 	printf("%d\n", ft_strncmp("Hello World", "Hello World", 100));
// 	printf("%d\n", ft_strncmp("Hello World", "Hello World", 0));
// }