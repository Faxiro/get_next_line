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
#include <stdio.h>
#include <string.h>

/*
gnl appele find_new_line

find_new_line cherche un retour a la ligne

si pas de retour a la ligne mais quand meme des choses dans storage, renvoyer 
la derniere ligne

si rien dans storage, appeler la fonction read_file + find new_line si il a
lu quelque chose

si il y a un retour a la ligne renvoyer la phrase + cut la phrase renvoyé et 
fermer le programme
*/

char	*read_file(int fd, char *storage)
{
	char	*buf;
	int		readed;
	int		nl;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
	{
		return (NULL);
	}
	readed = read(fd, buf, BUFFER_SIZE);
	while (readed >= 0)
	{
		if (readed == -1 || (readed == 0 && storage[0] == '\0'))
		{
			free(buf);
			free(storage);
			return (NULL);
		}
		buf[readed] = '\0';
		storage = add_to_buffer(buf, storage);
		nl = find_new_line(storage);
		if (nl >= 0)
		{
			return (free(buf), storage);
		}
		readed = read(fd, buf, BUFFER_SIZE);
	}
	return (free(buf), storage);
}

int	find_new_line(char *storage)
{
	int	i;

	i = 0;
	if (storage[0] == '\0')
		return (0);
	while (storage[i])
	{
		if (storage[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*add_to_buffer(char *buf, char *storage)
{
	char	*added;

	added = ft_strjoin(storage, buf);
	free(storage);
	return (added);
}

char	*cut_line(int cut, char **storage_pt, int i)
{
	char	*line;
	char	*tempo;
	
	if (*storage_pt == NULL)
		return (NULL);
	line = malloc(sizeof(char) * cut + 2);
	if (line == NULL)
		return (NULL);
	while ((*storage_pt)[i] && i <= cut)
	{
		line[i] = (*storage_pt)[i];
		i++;
	}
	line[i] = '\0';
	tempo = ft_substr(*storage_pt, cut + 1, ft_strlen(*storage_pt) - cut);
	if (tempo == NULL)
		return (NULL);
	free(*storage_pt);
	*storage_pt = ft_strdup(tempo);
	free(tempo);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*storage = 0;
	int			cut;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	storage = read_file(fd, storage);
	if (storage == NULL)
		return (NULL);
	cut = find_new_line(storage);
	return (cut_line(cut, &storage, 0));
}
