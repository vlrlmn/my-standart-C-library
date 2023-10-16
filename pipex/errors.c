/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinavaleria <lomakinavaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 02:41:33 by alabdull          #+#    #+#             */
/*   Updated: 2023/10/16 17:39:10 by lomakinaval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void call_err(char *msg)
{
	perror(msg);
	free(msg);
	exit(EXIT_FAILURE);
}

void	fd_error(int fd, int *end)
{
	perror("no such file or directory\n");
	close(fd);
	close(end[0]);
	close(end[1]);
	exit(2);
}

void	execve_error(char **cmd)
{
	ft_putstr_fd(cmd[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	free1(cmd);
	exit(126);
}

