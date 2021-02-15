/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:00:46 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/15 10:44:54 by edi-marc         ###   ########.fr       */
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
	void		*bf_r;
	size_t		ln_b;
	struct s_fd	*next;
}				t_fd;

int				get_next_line(int fd, char **line);
int				add_fd(t_fd **fdtable, int fd);
t_fd			*get_fd(t_fd *ptr_fd, int fd);
void			del_fd(t_fd **fdtable, t_fd *ptr_fd);
void			*ft_memchr(const void *s, int c, size_t n);
void			*ft_memcpy(void *dst, const void *src, size_t n);
int				mv_buf_ln(t_fd *ptr_fd, char **line, int res);
int				adj_buff(t_fd *ptr_fd, size_t n_b, int res);
int				mv_buf_to_buf_fd(t_fd *ptr_fd, char *buf, int res);
int				final_check(int res, t_fd *ptr_fd, t_fd **fdtable);

#endif
