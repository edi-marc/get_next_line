/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_O_MAX.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:20:16 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/10 11:29:02 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Maximum numbers of files that can be opened at the same time
**	The limit is a macro defined in limits.h (POSIX Library)
*/

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("OPEN_MAX= %d\n", OPEN_MAX);
	return (0);
}
