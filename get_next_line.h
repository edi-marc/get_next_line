/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/11 19:59:38 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/18 09:35:05 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

char	*get_next_line(int fd);
size_t	ft_strlen(const char *s);
char	*line_malloc(int fd, char *str);
char	*next_line(char *str);
char	*clean_line(char *line);
char	*ft_strchr_s(const char *str, int c);
char	*ft_strjoin_s(char *s1, char *s2);

#endif
