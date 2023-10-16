/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:26:38 by alabdull          #+#    #+#             */
/*   Updated: 2023/10/16 17:39:16 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>
# include "Libft/libft.h"

int		check_path(char **envp);
char	*get_path(char *argv, char **envp);
void	child_process(int *fds, char **argv, char **envp);
void	parent_process(int *fds, char **argv, char **envp);
void	fd_error(int fd, int *fds);
void	execve_error(char **cmd);
void	arg_error(int exit_1);
void	free1(char **p);
void	free2(char **p1, char **p2);
void call_err(char *msg);

#endif