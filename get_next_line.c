/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tleroy <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/30 17:12:53 by tleroy            #+#    #+#             */
/*   Updated: 2023/06/01 18:45:21 by tleroy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "get_next_line.h"

char	*add_to_buffer(char *buf, char *storage)
{
	char	*added;

	added = ft_strjoin(storage, buf);
	free(storage);
	return (added);
}

char	*get_line(char *storage)
{
	char	*line;
	int		i;
	
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
	line = ft_calloc(i + 2, sizeof(char);
	if (line == 0)
		return (NULL);
	i = 0;
	while (storage[i] && storage[i] != '\n')
	{
		line[i] = storage[i];
		i++;
	}
	line[i] = '\n';
	return (line);
}

char	*cut_line(char * storage)
{
	char	*new_storage;
	int		i;
	int		j;
	
	i = 0;
	while (storage[i] && storage[i] != '\n')
		i++;
// 	if (storage[i] == 0)
// 	{
// 		free(storage);
// 		return (NULL);
// 	}
	new_storage = ft_calloc(i + 1, sizeof(char));
	if (new_storage == 0)
		return (NULL);
	j = 0;
	while (storage[i])
		new_storage[j++] = storage[i++];
	free(storage);
	return (new_storage);
}

char	*read_file(int fd, char *storage)
{
	char	*buf;
	int		readed;
	
	buf = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if (buf == NULL)
		return (NULL);
	readed = 1;
	while (readed > 0)
	{
		readed = read(fd, buf, storage);
		if (readed == -1)
		{
			free(buf);
			free(storage);
			return (NULL);
		}
		buf[readed] = '\0';
		storage = add_to_buffer(buf, storage);
		readed = 0;
		while (storage[readed] && storage[readed] != '\n')
			readed++;
		if (storage[readed] && storage[readed] == '\n')
			return (free(buf), storage)
	}
	return (free(buf), storage);
}

char	*get_next_line(int fd)
{
	static char	*storage = 0;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0))
		return (NULL);
	storage = read_file(fd, storage);
	if (storage == NULL)
		return (NULL);
	line = get_line(storage);
	storage = cut_line(storage);
	return (line);
}
					 
