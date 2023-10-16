/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinargvaleria <lomakinargvaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:27:00 by alabdull          #+#    #+#             */
/*   Updated: 2023/10/16 17:38:14 by lomakinargval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	ft_execve(char *argv, char **envp)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv, ' ');
	path = get_path(cmd[0], envp);
	if (path)
	{
		if (execve(path, cmd, envp) == -1)
			execve_error(cmd);
	}
	else
		execve_error(cmd);
}

void	child_process(int *fds, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		fd_error(fd, fds);
	dup2(fd, STDIN_FILENO);
	dup2(fds[1], STDOUT_FILENO);
	close(fds[0]);
	ft_execve(argv[2], envp);
}

void	parent_process(int *fds, char **argv, char **envp)
{
	int		fd;

	fd = open(argv[4], O_CREAT | O_RDWR | O_TRUNC, 0644);
	if (fd == -1)
		fd_error(fd, fds);
	dup2(fd, STDOUT_FILENO);
	dup2(fds[0], STDIN_FILENO);
	close(fds[1]);
	ft_execve(argv[3], envp);
}

int	main(int ac, char **argv, char **envpp)
{
	int		fds[2];
	pid_t	pid;

	if (ac != 5)
	{
		write(1, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(EXIT_FAILURE);
	}
	if (pipe(fds) == -1)
		call_err("Pipe error");
	pid = fork();
	if (pid == -1)
		call_err("Fork error");
	if (pid == 0)
		child_process(fds, argv, envpp);
	wait(NULL);
	parent_process(fds, argv, envpp);
}
