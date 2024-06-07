/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:52:27 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/05 13:40:04 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	substrcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s2[i] == '\0')
	{
		return (0);
	}
	return (s1[i] - s2[i]);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;

	i = 0;
	if (to_find[0] == '\0')
		return (str);
	while (str[i] != '\0')
	{
		if (substrcmp(&str[i], to_find) == 0)
		{
			return (&str[i]);
		}
		i++;
	}
	return (0);
}
// #include <stdio.h>
// int main()
// {
// 	char str1[] = "Hello World! its a good day to be alive!";
// 	char str2[] = "alive!";
// 	printf("%s\n", ft_strstr(str1, str2));
// }