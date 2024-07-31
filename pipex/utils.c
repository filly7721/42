/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:47:02 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/27 19:47:03 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	free_strs(char **strs)
{
	int	i;

	i = 0;
	if (strs == NULL)
		return ;
	while (strs[i] != NULL)
		free(strs[i++]);
	free(strs);
}

static char	*ft_strappend(char *str1, char *str2)
{
	char	*res;

	if (str1 == NULL || str2 == NULL)
		return (NULL);
	res = ft_strjoin(str1, str2);
	free(str1);
	return (res);
}

char	*get_path(char *cmd, char **env)
{
	char	**paths;
	char	*path;
	int		i;

	i = 0;
	while (env[i] != NULL && ft_strnstr(env[i], "PATH", 4) == 0)
		i++;
	if (env[i] == NULL)
		return (cmd);
	paths = ft_split(env[i] + 5, ':');
	if (!paths)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	i = 0;
	while (paths[i])
	{
		path = ft_strappend(ft_strjoin(paths[i], "/"), cmd);
		if (!path)
			return (free_strs(paths), NULL);
		if (access(path, X_OK) == 0)
			return (free_strs(paths), path);
		free(path);
		i++;
	}
	free_strs(paths);
	return (cmd);
}

void	here_doc_in(char *limiter)
{
	char	*line;

	if (!limiter)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	while (1)
	{
		line = get_next_line(0);
		if (!line || ft_strncmp(line, limiter, ft_strlen(limiter) + 1) == 0)
			(free(line), free(limiter), exit(0));
		ft_putstr_fd(line, 1);
		free(line);
	}
}

void	here_doc(char *limiter)
{
	int		fds[2];
	pid_t	pid;

	if (pipe(fds) == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	pid = fork();
	if (pid == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	if (pid == 0)
	{
		if (dup2(fds[1], 1) == -1 || close(fds[1]) == -1 || close(fds[0]) == -1)
			(ft_putendl_fd(DEF_ERR, 2), exit(1));
		here_doc_in(ft_strjoin(limiter, "\n"));
	}
	if (dup2(fds[0], 0) == -1 || close(fds[1]) == -1 || close(fds[0]) == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	wait(NULL);
}
