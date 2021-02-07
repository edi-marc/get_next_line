/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:00:46 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/07 18:25:49 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

typedef	struct	s_fd
{
	int			fd;
	ssize_t		nbytes;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int fd, char **line);
void			add_fd(t_fd **fdtable, int fd);

#endif
