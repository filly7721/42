/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 13:29:58 by ashalaab          #+#    #+#             */
/*   Updated: 2024/06/14 13:29:58 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strappend(char *s1, char const *s2)
{
	char	*res;

	res = ft_strjoin(s1, s2);
	free(s1);
	if (!res)
		return (NULL);
	return (res);
}

char	*read_line(int fd, char *prev)
{
	char	*line;
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	bytes = 1;
	line = ft_strdup(prev);
	while (line != NULL && bytes > 0 && !ft_strchr(line, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(line);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		line = ft_strappend(line, buff);
	}
	free(buff);
	return (line);
}

char	*split_line(char *line, char *prev)
{
	int		i;
	char	*res;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
	{
		free(line);
		return (NULL);
	}
	ft_strcpy(prev, line + i);
	res[i] = '\0';
	while (i-- > 0)
		res[i] = line[i];
	free(line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	prev[1024][BUFFER_SIZE + 1U];
	char		*line;

	if (fd > 1023 || fd < 0)
		return (NULL);
	line = read_line(fd, prev[fd]);
	if (line && line[0] != '\0')
		line = split_line(line, prev[fd]);
	else if (!line)
		prev[fd][0] = '\0';
	else if (line)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
