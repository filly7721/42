/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 19:36:31 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/04 19:44:32 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

// #include <stdio.h>
// int main()
// {
// 	printf("%d\n", ft_strcmp("Hello", "Hello"));
// 	printf("\n");
// 	printf("%d\n", ft_strcmp("Hell", "Hello"));
// 	printf("%d\n", ft_strcmp("Hello", "Hell"));
// 	printf("\n");
// 	printf("%d\n", ft_strcmp("Hell0 World", "Hello World"));
// 	printf("%d\n", ft_strcmp("Hello World", "Hell0 World"));
// }