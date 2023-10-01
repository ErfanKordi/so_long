/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekordi <ekordi@student.42heilbronn.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 18:47:02 by ekordi            #+#    #+#             */
/*   Updated: 2023/04/24 13:39:14 by ekordi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_read(int fd, char *buffer)
{
	char	*new_buff;
	int		bytes_read;

	new_buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (!new_buff)
		return (NULL);
	bytes_read = 1;
	while (check_new_line(buffer) == -1 && bytes_read != 0)
	{
		bytes_read = read(fd, new_buff, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(new_buff);
			free(buffer);
			return (NULL);
		}
		new_buff[bytes_read] = '\0';
		buffer = ft_strjoin(buffer, new_buff);
	}
	free(new_buff);
	return (buffer);
}

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		c;
	int		i;

	c = 0;
	i = 0;
	if (!buffer[c])
		return (NULL);
	while (buffer[c] && buffer[c] != '\n')
		c++;
	if (buffer[c] == '\n')
		c++;
	line = ft_calloc(c + 1, sizeof(char));
	if (!line)
		return (NULL);
	c = 0;
	while (buffer[c] && buffer[c] != '\n')
		line[i++] = buffer[c++];
	if (buffer[c] == '\n')
		line[i++] = buffer[c++];
	return (line);
}

char	*ft_buffer_cut(char *buffer)
{
	char	*holder;
	int		i;
	int		j;

	j = 0;
	while (buffer[j] && buffer[j] != '\n')
		j++;
	if (buffer[j] == '\0')
	{
		free(buffer);
		return (NULL);
	}
	holder = ft_calloc((ft_strlen(buffer) + 1) - j, sizeof(char));
	if (!holder)
		return (NULL);
	j++;
	i = 0;
	while (buffer[j] != '\0')
		holder[i++] = buffer[j++];
	holder[i] = '\0';
	free(buffer);
	return (holder);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (free(buffer), NULL);
	line = ft_get_line(buffer);
	buffer = ft_buffer_cut(buffer);
	return (line);
}
