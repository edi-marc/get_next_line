/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 18:34:10 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/11 17:16:03 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	Only for testing purpose during development
**
*/

#include "get_next_line.h"
#include <stdio.h>

void	print_fdtable(t_fd *ptr_fd)
{
	int i;

	i = 0;
	while (ptr_fd)
	{
		printf("- FD [%d] -\n", i);
		printf("fd : %d, buff : %s, len_b : %lu\n", ptr_fd->fd, ptr_fd->bf_r, ptr_fd->ln_b);
		ptr_fd = ptr_fd->next;
		i++;
	}
}

void	print_fd(t_fd *ptr_fd)
{
	if (ptr_fd)
	{
		printf("- FD -\n");
		printf("fd : %d, buff : %s, len_b : %lu\n", ptr_fd->fd, ptr_fd->bf_r, ptr_fd->ln_b);
	}
}
