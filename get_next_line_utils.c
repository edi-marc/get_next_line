/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 19:35:29 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/06 19:48:58 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	new_fd(t_fd **fdtable, int fd)
{
	t_fd	*new_fd;

	new_fd = malloc(sizeof(*new_fd));
	if (new_fd)
	{
		new_fd->fd = fd;
		new_fd->nbytes = 0;
		new_fd->next = NULL;	
		if (*fdtable)
			new_fd->next = *fdtable;
		*fdtable = new_fd;
	}
}


