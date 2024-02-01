/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ialzein <ialzein@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:58:01 by ialzein           #+#    #+#             */
/*   Updated: 2023/11/23 09:52:42 by ialzein          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_read(int fd, char *file)
{
	char	*string;
	int		string_size;

	string = malloc(sizeof(char) *((size_t) BUFFER_SIZE + 1));
	if (!string)
		return (NULL);
	string_size = 1;
	while (!ft_strchr(file, '\n') && string_size != 0)
	{
		string_size = read(fd, string, BUFFER_SIZE);
		if (string_size == -1)
			return (free(string), free(file), NULL);
		string[string_size] = '\0';
		file = ft_strjoin(file, string);
	}
	return (free(string), file);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	line = malloc(sizeof(char) * (++i + 1));
	if (!line)
		return (NULL);
	i = 0;
	while (buffer[i] && buffer[i] != '\n')
	{
		line[i] = buffer[i];
		i++;
	}
	if (buffer[i] == '\n')
	{
		line[i] = '\n';
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_rest(char *buffer)
{
	char	*rest;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] != '\0' && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\0')
		return (free(buffer), NULL);
	rest = malloc(sizeof(char) * (ft_strlen(buffer) - i));
	if (rest == NULL)
		return (NULL);
	i++;
	if (buffer[i] == '\0')
		return (free (rest), free(buffer), NULL);
	j = 0;
	while (buffer[i])
		rest[j++] = buffer[i++];
	rest[j] = '\0';
	return (free(buffer), rest);
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	buffer[fd] = ft_read(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = ft_get_line(buffer[fd]);
	buffer[fd] = get_rest(buffer[fd]);
	return (line);
}
