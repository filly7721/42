/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ashalaab <ashalaab@student.42abudhabi.ae>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/27 19:46:58 by ashalaab          #+#    #+#             */
/*   Updated: 2024/07/27 19:46:59 by ashalaab         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec(char *str, char **env)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(str, ' ');
	if (!cmd)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	path = get_path(cmd[0], env);
	if (execve(path, cmd, env) == -1)
	{
		ft_putstr_fd("pipex: command not found: ", 2);
		ft_putendl_fd(cmd[0], 2);
		free_strs(cmd);
		exit(127);
	}
}

void	pipex(char *str, char **env)
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
		exec(str, env);
	}
	if (dup2(fds[0], 0) == -1 || close(fds[1]) == -1 || close(fds[0]) == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
}

void	first_pipex(char *str, char **env, char *file_name)
{
	pid_t	pid;
	int		infile;
	int		fds[2];

	if (pipe(fds) == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	pid = fork();
	if (pid == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	if (pid == 0)
	{
		infile = open(file_name, O_RDONLY);
		if (infile == -1 || dup2(infile, 0) == -1 || close(infile) == -1)
			(ft_putstr_fd("pipex: error opening file: ", 2),
				ft_putendl_fd(file_name, 2), exit(1));
		if (dup2(fds[1], 1) == -1 || close(fds[1]) == -1 || close(fds[0]) == -1)
			(ft_putendl_fd(DEF_ERR, 2), exit(1));
		exec(str, env);
	}
	if (dup2(fds[0], 0) == -1 || close(fds[0]) == -1 || close(fds[1]) == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
}

pid_t	last_pipex(char *str, char **env, char *file_name, int append)
{
	int		outfile;
	int		flags;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		(ft_putendl_fd(DEF_ERR, 2), exit(1));
	if (pid == 0)
	{
		flags = O_WRONLY | O_CREAT | O_TRUNC;
		if (append)
			flags = O_WRONLY | O_CREAT | O_APPEND;
		outfile = open(file_name, flags, 0644);
		if (outfile == -1 || dup2(outfile, 1) == -1 || close(outfile) == -1)
			(ft_putstr_fd("pipex: error opening file: ", 2),
				ft_putendl_fd(file_name, 2), exit(1));
		exec(str, env);
	}
	close(0);
	return (pid);
}

int	main(int ac, char **av, char **env)
{
	int		i;
	int		is_heredoc;
	pid_t	pid;
	int		status;

	if (ac < 5)
		(ft_putstr_fd("./pipex file1 cmd1 cmd2 file2\n", 2), exit(1));
	i = 1;
	is_heredoc = ft_strncmp(av[i], "here_doc", ft_strlen("here_doc") + 1) == 0;
	if (is_heredoc)
		here_doc(av[++i]);
	else
		first_pipex(av[++i], env, av[1]);
	while (++i < ac - 2)
		pipex(av[i], env);
	pid = last_pipex(av[i], env, av[i + 1], is_heredoc);
	waitpid(pid, &status, 0);
	while (wait(NULL) != -1)
		;
	return (WEXITSTATUS(status));
}
