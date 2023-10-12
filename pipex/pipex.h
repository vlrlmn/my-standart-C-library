/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:43:28 by vlomakin          #+#    #+#             */
/*   Updated: 2023/10/12 12:21:05 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "Libft/libft.h"
# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <errno.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>

void	make_fork(char *argv[], char **envp, int fd[]);
void	cmd1_exec(char *file1, char *cmd1, int fd[2], char **envp);
void	cmd2_exec(char *file2, char *cmd2, int fd[2], char **envp);
void	exec_cmd(char **envp, char *cmd);
char	*get_path(char **envp, char *cmd);
char	*find_path(char **envp, char *cmd);
void	reterr(char *msg);

#endif