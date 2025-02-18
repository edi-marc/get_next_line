/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 14:53:03 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/18 17:40:27 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*buffer[4096];

	line = NULL;
	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	buffer[fd] = line_malloc(fd, buffer[fd]);
	if (!buffer[fd])
		return (NULL);
	line = next_line(buffer[fd]);
	buffer[fd] = clean_line(buffer[fd]);
	return (line);
}
