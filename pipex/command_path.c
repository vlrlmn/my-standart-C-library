/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomakinargvaleria <lomakinargvaleria@studen    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 18:42:47 by alabdull          #+#    #+#             */
/*   Updated: 2023/10/16 17:08:52 by lomakinargval      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_path(char **envp)
{
	int	i;

	i = 0;
	while (envp[i])
	{
		if (ft_strncmp(envp[i], "PATH=", 5) == 0)
			return (1);
		i++;
	}
	return (0);
}

int	find_path(char **envp)
{
	int	i;

	i = 0;
	while (!ft_strnstr(envp[i], "PATH=", 5))
		i++;
	return (i);
}

char	*get_path(char *argv, char **envp)
{
	char	*path;
	char	**full_path;
	char	**command;
	int		i;

	if (check_path(envp) == 0)
		return (argv);
	if (ft_strchr(argv, '/'))
		return (argv);
	i = find_path(envp);
	full_path = ft_split(envp[i] + 5, ':');
	command = ft_split(argv, ' ');
	i = -1;
	while (full_path[++i])
	{
		path = ft_strjoin(ft_strjoin(full_path[i], "/"), command[0]);
		if (access(path, F_OK | X_OK) == 0)
		{
			free2(full_path, command);
			return (path);
		}
		free(path);
	}
	free2(full_path, command);
	return (NULL);
}
