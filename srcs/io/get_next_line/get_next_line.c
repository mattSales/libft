/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msales-a <msales-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/16 07:41:26 by msales-a          #+#    #+#             */
/*   Updated: 2021/04/28 23:29:51 by msales-a         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		buffer_load(int fd, char **buffer)
{
	char	*temp_read;
	char	*temp_buffer;
	int		length;

	if (!*buffer)
		*buffer = ft_strdup("");
	if ((temp_read = malloc(sizeof(char) * (BUFFER_SIZE + 1))) == 0)
		return (-1);
	if ((length = read(fd, temp_read, BUFFER_SIZE)) == -1)
		return (-1);
	temp_read[length] = '\0';
	if ((temp_buffer = ft_strjoin(*buffer, temp_read)) == 0)
		return (-1);
	free(*buffer);
	free(temp_read);
	*buffer = temp_buffer;
	return (length);
}

int		buffer_discharge(char **buffer, char **line)
{
	int		length;
	int		bsize;
	char	*temp;

	if (!*buffer)
	{
		*line = ft_strdup("");
		return (0);
	}
	bsize = ft_strlen(*buffer);
	length = ft_strchr(*buffer, '\n') - *buffer;
	*line = ft_substr(*buffer, 0, length);
	temp = ft_substr(*buffer, length + 1, ft_strlen(*buffer));
	free(*buffer);
	*buffer = temp;
	if (**buffer == '\0')
	{
		free(*buffer);
		*buffer = NULL;
	}
	return (bsize - ft_abs(length) > 0);
}

int		get_next_line(int fd, char **line)
{
	static char	*buffer[OPEN_MAX];
	int			length;

	if (!line || 0 > fd || fd >= OPEN_MAX || BUFFER_SIZE <= 0)
		return (-1);
	length = 0;
	while (!buffer[fd] || *ft_strchr(buffer[fd], '\n') != '\n')
	{
		if ((length = buffer_load(fd, &buffer[fd])) == -1)
			return (-1);
		if (length < BUFFER_SIZE)
			break ;
	}
	if (!buffer_discharge(&buffer[fd], line) && length < BUFFER_SIZE)
		return (0);
	return (1);
}
