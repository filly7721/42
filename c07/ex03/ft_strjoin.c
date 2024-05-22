/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 20:39:16 by ashalaab          #+#    #+#             */
/*   Updated: 2024/05/22 16:48:36 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*create_str(int size, char **strs, char *sep)
{
	int		i;
	char	*str;
	int		len;

	len = 0;
	i = 0;
	while (i < size)
		len += str_len(strs[i++]);
	len += str_len(sep) * (size - 1);
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	return (str);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*str;
	int		i;
	int		j;
	int		k;

	if(size < 1)
	{
		str = malloc(sizeof(char));
		str[0] = '\0';
		return (str);
	}
	str = create_str(size, strs, sep);
	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j] != '\0')
		{
			str[k++] = strs[i][j];
			j++;
		}
		j = 0;
		while (sep[j] != '\0' && i < size - 1)
		{
			str[k++] = sep[j];
			j++;
		}
	}
	str[k] = '\0';
	return (str);
}

// #include <stdio.h>
// int main(int argc, char *argv[])
// {
// 	if(argc < 3)
// 		return -1;

// 	printf("%s", ft_strjoin(0, &argv[2], argv[1]));
// }