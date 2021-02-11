/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:35:29 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/11 19:59:34 by edi-marc         ###   ########.fr       */
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
			new_fd->bf_r = NULL;
			new_fd->ln_b = 0;
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
		if (ptr_fd->bf_r)
			free(ptr_fd->bf_r);
		ptr_fd->ln_b = 0;
		ptr_fd->next = NULL;
		free(ptr_fd);
	}
}

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t i;

	i = 0;
	if (s)
	{
		while (i < n)
		{
			if (((unsigned char *)s)[i] == (unsigned char)c)
				return (&(((void *)s)[i]));
			i++;
		}
		return (0);
	}
	return (0);
}

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t i;

	i = 0;
	if (!src && !dst)
		return (dst);
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}
