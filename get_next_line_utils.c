/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:35:29 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/09 17:05:05 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	add_fd:
**	add the fd to the fd table if it is not present,
**	return ERR if the malloc fails, 1 otherwise;
**
**	get_fd:
**	return the fd, NULL if not present;
**
**	del_fd:
**	delete the fd from the fd table;
*/

#include "get_next_line.h"

int		add_fd(t_fd **fdtable, int fd)
{
	int		done;
	t_fd	*new_fd;

	done = 1;
	if (!(get_fd(*fdtable, fd)))
	{
		new_fd = malloc(sizeof(*new_fd));
		if (new_fd)
		{
			new_fd->fd = fd;
			new_fd->buff_read = NULL;
			new_fd->next = NULL;
			if (*fdtable)
				new_fd->next = *fdtable;
			*fdtable = new_fd;
		}
		else
			done = ERR;
	}
	return (done);
}

t_fd	*get_fd(t_fd *ptr_fd, int fd)
{
	while (ptr_fd && ptr_fd->fd != fd)
		ptr_fd = ptr_fd->next;
	return (ptr_fd);
}

void	del_fd(t_fd **fdtable, t_fd *ptr_fd)
{
	t_fd *temp;

	temp = *fdtable;
	if (ptr_fd && *fdtable)
	{
		if (ptr_fd == *fdtable)
			*fdtable = ptr_fd->next;
		else
		{
			while (temp && (temp->next != ptr_fd))
				temp = temp->next;
			if (temp)
				temp->next = ptr_fd->next;
		}
		ptr_fd->fd = ERR;
		free(ptr_fd->buff_read);
		ptr_fd->next = NULL;
		free(ptr_fd);
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return (&(((void *)s)[i]));
		i++;
	}
	return (0);
}
