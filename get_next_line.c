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

char	*get_next_line(int fd)
{
	char    *buffer;

	if (!fd || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char )* BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);

	find_new_line(fd, buffer);	
	
}

char    *find_new_line(int fd, char *buffer)
{
	int		i;
	char	*to_write;

	i = 0;
	read(int fd, void *buffer, size_t BUFFER_SIZE);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n' && buffer[i])
	{
		to_write = malloc(sizeof(char)* i + 1);
		while (i >= 0)
				to_write[i] = buffer[i--];
	}
}