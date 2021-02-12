/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:43:03 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/12 17:20:04 by edi-marc         ###   ########.fr       */
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
	t_fd		*tmp_fd;

	fdtable = &ptr_fd;
	res = ERR;
	if (line && read(fd, buf, 0) == 0 && BUFFER_SIZE != 0 &&
			((res = add_fd(fdtable, fd)) != ERR))
	{
		tmp_fd = get_fd(ptr_fd, fd);
		*line = NULL;
		while (!(ft_memchr(tmp_fd->bf_r, 10, tmp_fd->ln_b)) && res != ERR)
		{
			res = read(tmp_fd->fd, buf, BUFFER_SIZE);
			if (res > 0)
				res = mv_buf_to_buf_fd(tmp_fd, buf, res);
		}
		if (!(res != ERR && (res = mv_buf_ln(tmp_fd, *line, res) > 0)))
			res = final_check(res, tmp_fd, fdtable);
	}
	return (res);
}

int	mv_buf_ln(t_fd *ptr_fd, char *dst, int res)
{
	size_t	n_b;

	n_b = ptr_fd->ln_b;
	if ((ft_memchr(ptr_fd->bf_r, 10, ptr_fd->ln_b)))
		n_b = ptr_fd->bf_r - (ft_memchr(ptr_fd->bf_r, 10, ptr_fd->ln_b));
	if ((dst = malloc((n_b + 1) * sizeof(*dst))))
	{
		dst[n_b + 1] = '\0';
		ft_memcpy(dst, ptr_fd->bf_r, n_b);
		if (res != EOF_RCHD)
			res = READL_OK;
		n_b++;
		res = adj_buff(ptr_fd, n_b, res);
	}
	else
		res = ERR;
	return (res);
}

int	adj_buff(t_fd *ptr_fd, size_t n_b, int res)
{
	void	*tmp_buf;
	size_t	new_len;

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
			res = ERR;
	}
	return (res);
}

int	mv_buf_to_buf_fd(t_fd *ptr_fd, char *buf, int res)
{
	void	*tmp_bf;

	if (!(tmp_bf = malloc((ptr_fd->ln_b + res) * sizeof(void *))))
		res = ERR;
	else
	{
		ft_memcpy(tmp_bf, ptr_fd->bf_r, ptr_fd->ln_b);
		ft_memcpy(tmp_bf + ptr_fd->ln_b + 1, buf, res);
		free(ptr_fd->bf_r);
		ptr_fd->ln_b = ptr_fd->ln_b + res;
		ptr_fd->bf_r = tmp_bf;
	}
	return (res);
}

int	final_check(int res, t_fd *ptr_fd, t_fd **fdtable)
{
	if (res == ERR)
		del_fd(fdtable, ptr_fd);
	else if (res == 0 && !ptr_fd->ln_b)
	{
		res = EOF_RCHD;
		del_fd(fdtable, ptr_fd);
	}
	else
		res = READL_OK;
	return (res);
}
