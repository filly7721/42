/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/04 13:27:39 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/04 15:07:16 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_alpha_numeric(char ch)
{
	if (ch >= '0' && ch <= '9')
		return (1);
	if (ch >= 'A' && ch <= 'Z')
		return (1);
	if (ch >= 'a' && ch <= 'z')
		return (1);
	return (0);
}

char	char_uppercase(char ch)
{
	if (ch >= 'a' && ch <= 'z')
		return (ch - ('a' - 'A'));
	return (ch);
}

char	char_lowercase(char ch)
{
	if (ch >= 'A' && ch <= 'Z')
		return (ch + ('a' - 'A'));
	return (ch);
}

char	*ft_strcapitalize(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (!is_alpha_numeric(str[i]))
		{
			i++;
			continue ;
		}
		str[i] = char_uppercase(str[i]);
		i++;
		while (str[i] != '\0')
		{
			if (!is_alpha_numeric(str[i]))
				break ;
			str[i] = char_lowercase(str[i]);
			i++;
		}
	}
	return (str);
}

//#include <stdio.h>
//int main()
//{
//char str[] = "salut, coMMEnT tU vaS ? 42mots quarante-deux; cinquante+et+un";
//
//   puts(str);
//    puts(ft_strcapitalize(str));   
//}
