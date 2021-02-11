/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:43:03 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/11 19:59:37 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	PARAMETERS: 	#1.	file descriptor for reading
**					#2.	The value of what has been read
**
**	RETURN VALUE:	1:	A line has been read
**					0:	EOF has been reached
**					-1:	An error happened
**
**	DESCRIPTION:	returns a line read from a fd, without \n
**
**	Consider that get_next_line has an undefined behavior if, between two calls,
**	the same file descriptor switches to a different
**	file before EOF has been reached on the first fd.
**
**	It is destructive on the content of line
**
**	If the buffer of a fd reach EOF, it is removed from the fd table
*/

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_fd	*ptr_fd;
	t_fd		**fdtable;
	char		buf[BUFFER_SIZE];
	int			res;
	t_fd		*temp_fd;

	fdtable = &ptr_fd;
	if (line && read(fd, buf, 0) == 0 && BUFFER_SIZE != 0 &&
			((res = add_fd(fdtable, fd)) != ERR))
	{
		temp_fd = get_fd(ptr_fd, fd);
		*line = NULL;

		if (ft_memchr(ptr_fd->bf_r, 10, ptr_fd->ln_b))
			res = mv_buf_ln(ptr_fd, *line, fdtable);
		else
			while ((res = read(fd, buf, BUFFER_SIZE)) > 0)	
	}
	return (res);
}

int	mv_buf_ln(t_fd *ptr_fd, char *dst, t_fd **fdtable)
{
	size_t	n_b;
	int		res;

	res = ERR;
	n_b = ptr_fd->bf_r - (ft_memchr(ptr_fd->bf_r, 10, ptr_fd->ln_b));
	if (!dst)
		dst = malloc((n_b + 1) * sizeof(*dst));
	if (dst)
	{
		dst[n_b + 1] = '\0';
		ft_memcpy(dst, ptr_fd->bf_r, n_b);
		res = READL_OK;
		n_b++;
		res = adj_buff(ptr_fd, n_b, fdtable);
	}
	return (res);
}

int	adj_buff(t_fd *ptr_fd, size_t n_b, t_fd **fdtable)
{
	int		res;
	void	*tmp_buf;
	size_t	new_len;

	res = READL_OK;
	if (ptr_fd->ln_b - n_b)
	{
		new_len = ptr_fd->ln_b - n_b;
		if ((tmp_buf = malloc(new_len * sizeof(*tmp_buf))))
		{
			ft_memcpy(tmp_buf, (ptr_fd->bf_r) + n_b, new_len);
			free(ptr_fd->bf_r);
			ptr_fd->bf_r = tmp_buf;
		}
		else
		{
			res = ERR;
			del_fd(fdtable, ptr_fd);
		}
	}
	else
		del_fd(fdtable, ptr_fd);
	return (res);
}
