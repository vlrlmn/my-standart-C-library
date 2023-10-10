#include "pipex.h"

// void ft_free_str_arr(char **arr)
// {
// 	int i;
// 	i = 0;

// 	if (!arr)
// 		return;
// 	while(arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);
// }

// char *get_cmd_path(char **paths, char *sub)
// {
// 	char *cmd_path;
// 	int i;
// 	i = 0;

// 	while(paths && paths[i])
// 	{
// 		cmd_path = ft_strjoin(paths[i], sub);
// 		if (!cmd_path)
// 			break;
// 		if (!access(cmd_path, F_OK | X_OK))
// 			break;
// 		free(cmd_path);
// 		cmd_path = NULL;
// 		i++;
// 	}
// 	return (cmd_path);
// }

// char *get_env_path(char **envp)
// {
// 	int i;
// 	char *res;

// 	i = 0;
// 	while(envp[i] && !ft_strnstr(envp[i], "PATH=", 5))
// 		i++;
// 	if(!envp[i])
// 		return (NULL);
// 	res = ft_substr(envp[i], 5, ft_strlen((envp[i]) - 5));
// 	return (res);
// }

// char *get_actual_cmd(char *cmd)
// {
// 	char **result;

// 	result = ft_split(cmd, ' ');
// 	return (*result);
// }

// char	*get_path(char **envp, char *cmd)
// {
// 	char	**paths;
// 	char	*cmd_path;
// 	char	*sub;
// 	char	*actual_cmd;
// 	char	*env_path;

// 	actual_cmd = get_actual_cmd(cmd);
// 	env_path = get_env_path(envp);
// 	if (!env_path)
// 	{
// 		free(actual_cmd);
// 		return (NULL);
// 	}
// 	paths = ft_split(env_path, ':');
// 	free(env_path);
// 	sub = ft_strjoin("/", actual_cmd);
// 	cmd_path = get_cmd_path(paths, sub);
// 	free(sub);
// 	free(actual_cmd);
// 	ft_free_str_arr(paths);
// 	return (cmd_path);
// }

void	reterr( char *err_msg)
{
	write (1, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

void	reterr_f(char *err_msg)
{
	write (1, err_msg, ft_strlen(err_msg));
	exit(EXIT_FAILURE);
}

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*sub;

	cmd = *ft_split(cmd, ' ');
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
	if (!*envp || !envp)
	{
		free(cmd);
		reterr("No such file or directory");
		exit(1);
	}
	sub = ft_substr(*envp, 5, ft_strlen(*envp) - 5);
	paths = ft_split(sub, ':');
	free(sub);
	sub = ft_strjoin("/", cmd);
	while (*paths)
	{
		cmd_path = ft_strjoin(*paths, sub);
		if (!cmd_path)
			return (NULL);
		if (!access(cmd_path, F_OK))
			break ;
		free(cmd_path);
		paths++;
	}
	free(sub);
	free(cmd);
	return (cmd_path);
}

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
	fd_n = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd_n == -1)
	{
		strerror(errno);
	}
	dup2(fd[0], STDIN_FILENO);
	close(fd[0]);
	dup2(fd_n, STDOUT_FILENO);
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
		strerror(errno);
	}
	dup2(fd[1], STDOUT_FILENO);
	close(fd[1]);
	dup2(fd_n, STDIN_FILENO);
	exec_cmd(envp, cmd1);
	exit(EXIT_SUCCESS);
}

int	main(int argc, char *argv[], char **envp)
{
	int	fd[2];
	pid_t	pid;

	if (argc != 5)
	{
		write(1, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
		exit(1);
	}
	if (pipe(fd) == -1)
	{
		perror("Pipe error");
	}
	pid = fork();
	if (pid == -1)
	{
		perror("Fork failed");
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