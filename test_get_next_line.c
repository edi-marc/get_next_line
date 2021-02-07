/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:34:10 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/07 18:20:53 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	Only for testing purpose during development
**
*/

#include "get_next_line.h"
#include <stdio.h>

void	print_fd(t_fd *ptr_fd)
{
	int i;

	i = 0;
	while (ptr_fd)
	{
		printf("- FD [%d] -\n", i);
		printf("fd : %d, nbytes : %zd\n", ptr_fd->fd, ptr_fd->nbytes);
		ptr_fd = ptr_fd->next;
		i++;
	}
}
