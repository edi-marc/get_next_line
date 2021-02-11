/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:43:03 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/10 20:06:51 by edi-marc         ###   ########.fr       */
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
	res = ERR;
	if (line && read(fd, buf, 0) == 0 && BUFFER_SIZE != 0 &&
			(res = add_fd(fdtable, fd) != ERR))
	{
		temp_fd = get_fd(ptr_fd, fd);
		// check if the \n is present in the buffer
		if (temp_fd->buff_read)
		else
		while ((res = read(temp_fd->fd, buf, BUFFER_SIZE)) != ERR)
		{
			if (ft_memchr(buf, 10, res) && res)
			{

			}
			else

		}
		if (res == ERR)
			del_fd(temp_fd);
		else

	}
	return (res);
}

store buffer
	mette la parte letta dopo \n nel buffer corrispondente di fd

store in line
	mette la parte letta prima di \n in line
