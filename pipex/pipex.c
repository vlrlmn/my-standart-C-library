/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:43:32 by vlomakin          #+#    #+#             */
/*   Updated: 2023/10/12 12:33:16 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	exec_cmd(char **envp, char *cmd)
{
	char	*path;
	int		exec_status;

	path = get_path(envp, cmd);
	if (!path)
	{
		perror(cmd);
	}
	exec_status = execve(path, ft_split(cmd, ' '), envp);
	if (exec_status == -1)
	{
		perror("Failed to complete command");
	}
}

void	cmd2_exec(char *file2, char *cmd2, int fd[2], char **envp)
{
	int	fd_n;

	close(fd[1]);
	fd_n = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd_n == -1)
	{
		reterr(file2);
	}
	if (dup2(fd[0], STDIN_FILENO) == -1)
	{
		reterr("File descriptor is not valid");
	}
	else
		close(fd[0]);
	if (dup2(fd_n, STDOUT_FILENO) == -1)
	{
		reterr("File descriptor is not valid");
	}
	exec_cmd(envp, cmd2);
	exit(EXIT_SUCCESS);
}

void	cmd1_exec(char *file1, char *cmd1, int fd[2], char **envp)
{
	int	fd_n;

	close(fd[0]);
	fd_n = open(file1, O_RDONLY);
	if (fd_n == -1)
	{
		reterr(file1);
	}
	if (dup2(fd[1], STDOUT_FILENO) == -1)
	{
		reterr("File descriptor is not valid");
	}
	else
		close(fd[1]);
	if (dup2(fd_n, STDIN_FILENO) == -1)
	{
		reterr("File descriptor is not valid");
	}
	exec_cmd(envp, cmd1);
	exit(EXIT_SUCCESS);
}

void	make_fork(char *argv[], char **envp, int fd[])
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		reterr("Fork failed");
	}
	if (pid == 0)
	{
		cmd1_exec(argv[1], argv[2], fd, envp);
	}
	else
	{
		wait(NULL);
		cmd2_exec(argv[4], argv[3], fd, envp);
		close(fd[0]);
		close(fd[1]);
	}
}

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];

	if (argc != 5)
	{
		write(1, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(EXIT_FAILURE);
	}
	if (pipe(fd) == -1)
	{
		reterr("Pipe error");
	}
	make_fork(argv, envp, fd);
}
