/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/12 11:49:46 by vlomakin          #+#    #+#             */
/*   Updated: 2023/10/12 15:17:46 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	reterr(char *msg)
{
	perror(msg);
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
	if (!*envp && !ft_strnstr(*envp, "PATH=", 5))
	{
		free(cmd);
		reterr("No such file or directory");
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
		if (!access(cmd_path, F_OK | X_OK))
			break ;
		free(cmd_path);
		paths++;
	}
	free(sub);
	free(cmd);
	return (cmd_path);
}
