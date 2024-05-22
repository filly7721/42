/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/03 15:11:20 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/05 11:12:17 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src[i] == '\0')
			break ;
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

//#include <stdio.h>
//int main()
//{
//	char str1[] = "Hello World!";
//	char str2[] = "Im Gibberish";
//	puts(str2);
//	ft_strncpy(str2, str1, 10);
//	puts(str2);
//}
