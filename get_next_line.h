/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:00:46 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/08 19:08:16 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>

# define READL_OK 1
# define EOF_RCHD 0
# define ERR -1

typedef	struct	s_fd
{
	int			fd;
	void		*buff_read;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int fd, char **line);
int				add_fd(t_fd **fdtable, int fd);
t_fd			*get_fd(t_fd *ptr_fd, int fd);
void			del_fd(t_fd **fdtable, t_fd *ptr_fd);

#endif
