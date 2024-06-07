/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bugadzhi <bugadzhi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 20:25:00 by bugadzhi          #+#    #+#             */
/*   Updated: 2024/05/19 22:34:18 by bugadzhi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush02.h"

char	*strtrim(char *str)
{
	char	*res;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = ft_strlen(str) - 1;
	if (*str)
	{
		while (is_space(str[i]))
			i++;
		while (is_space(str[j]))
			j--;
	}
	res = (char *)malloc(sizeof(char) * (j - i + 2));
	if (res)
	{
		k = -1;
		while (i <= j)
			res[++k] = str[i++];
		res[++k] = '\0';
	}
	return (res);
}

long	ft_atoi(char *str)
{
	long	res;
	long	sign;

	sign = 1;
	res = 0;
	while (*str && ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	if (*str == '-')
		sign = -1;
	while (*str == '-' || *str == '+')
		str++;
	while (*str >= 48 && *str <= 57)
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (sign * res);
}

int	read_one_line(int fd, char **line)
{
	int		rd;
	int		i;
	char	ch;
	char	*buf;

	rd = 1;
	i = 0;
	buf = (char *)malloc(sizeof(char) * BYTE_COUNT);
	*line = buf;
	while ((rd > 0 && ch != '\n'))
	{
		rd = read(fd, &ch, 1);
		buf[i] = ch;
		i++;
	}
	buf[i] = '\0';
	return (rd);
}

char	*ft_memcpy(char *dest, char *src, int n)
{
	const char	*src_ptr;
	char		*dest_ptr;

	if (dest == src)
		return (dest);
	src_ptr = src;
	dest_ptr = dest;
	while (n--)
		*dest_ptr++ = *src_ptr++;
	return (dest);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*result;
	int		s1_len;
	int		s2_len;

	if (!s1 || !s2)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	result = malloc(s1_len + s2_len + 1);
	if (result)
	{
		ft_memcpy(result, s1, s1_len);
		ft_memcpy(result + s1_len, s2, s2_len + 1);
	}
	return (result);
}
