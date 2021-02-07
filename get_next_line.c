/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 14:43:03 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/07 20:27:06 by edi-marc         ###   ########.fr       */
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
**	the same file descriptor switches to a different file before EOF has been reached on
**	the first fd.
**
**	It is destructive on the content of line
**
**	If a fd reach EOF, it is removed from the fd table
*/

#include "get_next_line.h"

int	get_next_line(int fd, char **line)
{
	static t_fd	*ptr_fd;
	t_fd		**fdtable;
	char		buf[BUFFER_SIZE];

	fdtable = &ptr_fd;
	add_fd(fdtable, fd);

	print_fd(ptr_fd);

	return (1);
}
