/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:43:04 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/02 17:40:55 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
**
**	Main used to check the correct output of get_next_line function
**	
**	Focused on read from stdin or a text file, for the moment...
**
**	argv[1] = "C"					TEST read & write function
**	argv[1] = "0"					READ FROM stdin
**	argv[1] = "name_of_the_file"	READ FROM text file (in ~/Desktop/)
**
*/

#include "get_next_line.h"

#include <stdio.h>
//#include <fcntl1.h>

int main (int argc , char **argv)
{
	if(argc == 2)
	{
		/* pag. 171 - The C Programming Language */
		/* simple program to copy its input to its output */
		if (*argv[1] == 'C')
		{
			char buf[BUFFER_SIZE];
			int n;

			while ((n = read(0, buf, BUFFER_SIZE)) > 0)
				write(1, buf, n);
		}
		if (*argv[1] == '0')
		{
			char *p_line;
			char **line;

			p_line = NULL;
			line = &p_line;
			printf("\n--- PRIMA ---\n");
			printf("line : %s\n", *line);
			printf("\n--- DOPO ---\n");
			if (get_next_line(0, line))
				printf("line : %s\n", *line);

		}
		if (*argv[1])
		{

		}
	}
	return (0);
}
