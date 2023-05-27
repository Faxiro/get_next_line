/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 16:41:38 by aviscogl          #+#    #+#             */
/*   Updated: 2023/02/17 16:41:38 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/*
gnl appele find_new_line

find_new_line cherche un retour a la ligne

si pas de retour a la ligne mais quand meme des choses dans storage, renvoyer la derniere ligne

si rien dans storage, appeler la fonction read_file

si il y a un retour a la ligne renvoyer la phrase + cut la phrase renvoyé et fermer le programme
*/

char	*get_next_line(int fd)
{
	static char	*storage = 0;
	int			cut;
	char *		line;

	if (fd == -1 || BUFFER_SIZE <= 0)
		return (NULL);
	cut = find_new_line(storage);
	if (cut == 0)
	{
		cut = read_file(fd, storage);
		if (cut > 0)
		{	
			cut = find_new_line(storage);
			if (cut > 0)
				return(cut_line(cut, storage));
		}
		else
			free(storage);
			return (0);
	}
	else 
		return (cut_line(cut, storage));
	return (0);
}

int	find_new_line(char *storage)
{
	int	i;

	i = 0;
	while (storage[i] && storage [i] != '\n')
	{
		if (storage[i] == '\n')
			return(i);
		i++;
	}
	return (0);
}

char	*read_file(int fd, char *storage)
{
	char	*buf;
	char	*tempo;
	int		readed;

	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (buf == NULL)
		return (NULL);
	readed = read(fd, buf, BUFFER_SIZE);
	if (readed == 0 && storage[0] == NULL)
		end_file(storage, buf);
	tempo = ft_strjoin(storage, buf);
	free(storage);
	free(buf);
	storage = ft_strdup(tempo);
	free(tempo);
	return (readed);
}

int	end_file(char *storage, char *buf)
{
	free(storage);
	free(buf);
	return (0);
}

char	*cut_line(int cut, char *storage)
{
	char	*line;
	char	*tempo;
	int		i;

	line = malloc(sizeof(char) * cut + 1);
	if (line == NULL)
		return (NULL);
	i = 0;
	while (storage[i] && i <= cut)
		line[i] = storage [i++];
	line[i + 1] = '\0';
	tempo = malloc(sizeof(char) * ft_strlen(storage) - cut + 1);
	if (tempo == NULL)
		return (NULL);
	while (storage[i])
		tempo[i - cut] = storage[i++];
	tempo[i - cut + 1] = '\0';
	free(storage);
	storage = ft_strdup(tempo);
	free(tempo);
	return (line);
}
				to_write[i] = buffer[i--];
	}
}
