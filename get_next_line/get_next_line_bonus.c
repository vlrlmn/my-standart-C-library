/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vlomakin <vlomakin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 11:39:33 by vlomakin          #+#    #+#             */
/*   Updated: 2023/09/07 12:10:12 by vlomakin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



char	*join_read(char *save_line, char *buf)
{
	char	*concat;

	concat = ft_strjoin(save_line, buf);
	free(save_line);
	return (concat);
}

char	*remainder_chars(char *save_line)
{
	int		i;
	int		j;
	char	*remainder;

	i = 0;
	while (save_line[i] && save_line[i] != '\n')
		i++;
	if (save_line[i] == '\0')
	{
		free(save_line);
		return (NULL);
	}
	remainder = ft_calloc(sizeof(char), (ft_strlen(save_line) - i + 1));
	i++;
	j = 0;
	while (save_line[i])
	{
		remainder[j] = save_line[i];
		j++;
		i++;
	}
	free(save_line);
	return (remainder);
}

char	*final_line(char *save_line)
{
	char	*result;
	int		i;

	i = 0;
	if (!save_line[i])
		return (NULL);
	while (save_line[i] && save_line[i] != '\n')
		i++;
	result = ft_calloc(sizeof(char), (i + 1 + 1));
	i = 0;
	while (save_line[i] && save_line[i] != '\n')
	{
		result[i] = save_line[i];
		i++;
	}
	if (save_line[i] && save_line[i] == '\n')
		result[i++] = '\n';
	return (result);
}

char	*read_to_n(int fd, char *save_line)
{
	int		bytes_read;
	char	*buf;

	if (!save_line)
		save_line = ft_calloc(1, 1);
	buf = ft_calloc(sizeof(char), BUFFER_SIZE + 1);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buf, BUFFER_SIZE);
		if (bytes_read < 0)
		{
			free(buf);
			return (NULL);
		}
		buf[bytes_read] = '\0';
		save_line = join_read(save_line, buf);
		if (ft_strchr(save_line, '\n'))
			break ;
	}
	free(buf);
	return (save_line);
}

char	*get_next_line(int fd)
{
	static char	*save_line[OPEN_MAX];
	char		*result;

	if (fd < 0 || BUFFER_SIZE <= 0 || (read(fd, 0, 0) < 0))
		return (NULL);
	save_line[fd] = read_to_n(fd, save_line[fd]);
	if (!save_line[fd])
		return (NULL);
	result = final_line(save_line[fd]);
	save_line[fd] = remainder_chars(save_line[fd]);
	return (result);
}

// #include <stdio.h>

// int	main(void)
// {
// 	int fd;

// 	fd = open("alice_in_wonderland.txt", O_RDONLY);
//  	char *line = get_next_line(fd);

// 	while (line)
// 	{
// 		printf("%s", line);
// 		free(line);
//  		line = get_next_line(fd);
// 	}
// 	// printf("%s", get_next_line(fd));
// 	close(fd);
// }