/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:43:04 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/04 18:30:10 by edi-marc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
**
**	Main used to check the correct output of get_next_line function
**	
**	Focused on read from stdin or a text file, for the moment...
**
**	argv[1] = "C"					TEST read & write function
**	argv[1] = "0"					READ FROM stdin
**	argv[1] = "name_of_the_file"	READ FROM text file (in current directory)
**	
**	argv[1] = "name_of_the_file"	READ FROM text file (in current directory)
**	argv[2] = "E"					till the EOF
**
*/

#include "get_next_line.h"

#include <stdio.h>
#include <fcntl.h>

int main (int argc , char **argv)
{
	if (argc == 2)
	{
		/* pag. 171 - The C Programming Language */
		/* simple program to copy its input to its output */
		if (*argv[1] == 'C')
		{
			char buf[BUFFER_SIZE];
			int n;

			while ((n = read(0, buf, BUFFER_SIZE)) > 0)
				write(1, buf, n);

			return (0);
		}
		if (*argv[1] == '0')
		{
			char *p_line;
			char **line;
			int check;

			p_line = NULL;
			line = &p_line;
			printf("\n--- PRIMA ---\n");
			printf("%s\n", *line);
			printf("\n--- DOPO ---\n");
			if ((check = get_next_line(0, line)))
				printf("%s\n\n", *line);
			else if (check == -1)
				printf("An error happened\n");
			else if (check == 0)
				printf("EOF has been reached\n");

			return (0);
		}
		if (*argv[1])
		{
			int fd;

			if ((fd = open(argv[1], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[1]);
			else
			{	
				char *p_line;
				char **line;
				int check;

				p_line = NULL;
				line = &p_line;
				printf("\n--- PRIMA ---\n");
				printf("%s\n", *line);
				printf("\n--- DOPO ---\n");
				if ((check = get_next_line(fd, line)))
					printf("%s\n\n", *line);
				else if (check == -1)
					printf("An error happened\n");
				else if (check == 0)
					printf("EOF has been reached\n");
			}

			return (0);
		}
	}
	if (argc == 3)
	{
		if (*argv[1] && *argv[2] == 'E')
		{	
			int fd;

			if ((fd = open(argv[1], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[1]);
			else
			{	
				char *p_line;
				char **line;

				p_line = NULL;
				line = &p_line;
				printf("\n--- FILE ---\n");
				while ((get_next_line(fd, line)) > 0)
					printf("%s\n", *line);
			}

			return (0);
		}
	}

	return (0);
}
