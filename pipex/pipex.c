#include "pipex.h"

char	*get_path(char **envp, char *cmd)
{
	char	**paths;
	char	*cmd_path;
	char	*sub;

	cmd = *ft_split(cmd, ' ');
	while (*envp && !ft_strnstr(*envp, "PATH=", 5))
		envp++;
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

void exec_cmd(char **envp, char *cmd)
{
    char *path;
    int exec_status;

    path = get_path(envp, cmd);
    if (!path)
    {
        perror("Command not found");
        exit(EXIT_FAILURE);
    }
    exec_status = execve(path, ft_split(cmd, ' '), envp);
    if (exec_status == -1)
    {
        perror("Failed to complete command");
        exit(EXIT_FAILURE);
    }
}

void cmd2_exec(char *file2, char *cmd2, int fd[2], char **envp)
{
    int fd_n;

    close(fd[1]);
    fd_n = open(file2, O_WRONLY | O_CREAT | O_TRUNC, 0777);
    if (fd_n == -1)
    {
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }
    dup2(fd[0], STDIN_FILENO);
    close(fd[0]);
    dup2(fd_n, STDOUT_FILENO);
    exec_cmd(envp, cmd2);
    exit(EXIT_SUCCESS);
}

void cmd1_exec(char *file1, char *cmd1, int fd[2], char **envp)
{
    int fd_n;

    close(fd[0]);
    fd_n = open(file1, O_RDONLY);
    if (fd_n == -1)
    {
        perror("File cannot be opened");
        exit(EXIT_FAILURE);
    }
    dup2(fd[1], STDOUT_FILENO);
    close(fd[1]);
    dup2(fd_n, STDIN_FILENO);
    exec_cmd(envp, cmd1);
    exit(EXIT_SUCCESS);
}

int main(int argc, char *argv[], char **envp)
{
    int fd[2];
    pid_t pid;

    if (argc != 5) {
        write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
        exit(EXIT_FAILURE);
    }
    if (!envp) {
        write(2, "Usage: ./pipex file1 cmd1 cmd2 file2\n", 38);
        exit(EXIT_FAILURE);
    }
    if (pipe(fd) == -1) {
        perror("Pipe error");
        exit(EXIT_FAILURE);
    }
    pid = fork();
    if (pid == -1)
    {
        write(2, "Fork error", 11);
        exit(EXIT_FAILURE);
    }
    if (pid == 0) 
    {
        cmd1_exec(argv[1], argv[2], fd, envp);
    }
    else 
    {
        wait(NULL);
        close(fd[0]);
        close(fd[1]);
        cmd2_exec(argv[4], argv[3], fd, envp);
    }
}