/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aviscogl <aviscogl@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:24:58 by aviscogl          #+#    #+#             */
/*   Updated: 2023/02/17 17:24:58 by aviscogl         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *s)
{
    int i;

    i = 0;
    while (s[i])
        i++;
    return (i);
}

char	*ft_strdup(const char *s)
{
	char	*dup;
	int		size;
	int		i;

	i = -1;
	size = ft_strlen(s);
	dup = malloc(sizeof(char) * size + 1);
	if (dup == 0)
		return (0);
	while (++i < size)
		dup[i] = s[i];
	dup[i] = 0;
	return (dup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	char	*joined;

	joined = malloc(sizeof(*s1) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (joined == 0)
		return (0);
	i = -1;
	while (s1[++i])
		joined[i] = s1[i];
	j = -1;
	while (s2[++j])
	{
		joined[i] = s2[j];
		i++;
	}
	joined[i] = '\0';
	return (joined);
}
