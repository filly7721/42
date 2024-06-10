#include "get_next_line.h"

char	*read_line(int fd, char *curr)
{
	char	*buff;
	int		bytes;

	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	if (!curr)
		curr = ft_strdup("");
	bytes = 1;
	if (!curr)
		bytes = 0;
	while (bytes > 0 && !ft_strchr(curr, '\n'))
	{
		bytes = read(fd, buff, BUFFER_SIZE);
		if (bytes < 0)
		{
			free(curr);
			free(buff);
			return (NULL);
		}
		buff[bytes] = '\0';
		curr = ft_strappend(curr, buff);
	}
	free(buff);
	return (curr);
}

char	*split_line(char **prev)
{
	int		i;
	char	*res;
	char	*line;

	line = *prev;
	i = 0;
	while (line[i] != '\n' && line[i] != '\0')
		i++;
	if (line[i] == '\n')
		i++;
	res = malloc(sizeof(char) * (i + 1));
	*prev = ft_strdup(line + i);
	if (!res)
		return (NULL);
	res[i] = '\0';
	while (--i >= 0)
		res[i] = line[i];
	free (line);
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*prev[1024];
	char		*line;

	prev[fd] = read_line(fd, prev[fd]);
	if (prev[fd] && prev[fd][0] != '\0')
	{
		line = split_line(prev + fd);
		return (line);
	}
	if (prev[fd])
		free(prev[fd]);
	return (prev[fd] = NULL);
}
