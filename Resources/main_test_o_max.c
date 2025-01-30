/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_o_max.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 11:20:16 by edi-marc          #+#    #+#             */
/*   Updated: 2025/01/30 22:10:37 by emdi-mar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**	Maximum numbers of files that can be opened at the same time
**	The limit is a macro defined in limits.h (POSIX Library)
*/

/*
**	macOS Version
*/

/*

#include <limits.h>
#include <stdio.h>

int	main(void)
{
	printf("OPEN_MAX= %d\n", OPEN_MAX);
	return (0);
}

*/

/*
**	GNU/Linux - POSIX Version
*/

#include <unistd.h>
#include <stdio.h>

int	main(void)
{
	long	openmax;

	openmax = sysconf(_SC_OPEN_MAX);
	printf("OPEN_MAX= %ld\n", openmax);
	return (0);
}
