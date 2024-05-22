/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 13:00:27 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/05 13:40:25 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	destlen;
	unsigned int	srclen;

	i = 0;
	j = 0;
	j = ft_strlen(dest);
	destlen = j;
	srclen = ft_strlen(src);
	if (size == 0 || size <= destlen)
		return (srclen + size);
	while (src[i] != '\0' && i < size - destlen - 1)
		dest[j++] = src[i++];
	dest[j] = '\0';
	return (destlen + srclen);
}

// #include<stdio.h>
// int main()
// {
// 	char str1[13] = "Hello ";
// 	char str2[] = "World!";
//
// 	ft_strlcat(str1, str2, 8);
// 	printf("%s\n", str1);
// }