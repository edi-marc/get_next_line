/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/02 13:43:04 by edi-marc          #+#    #+#             */
/*   Updated: 2021/02/13 13:48:00 by edi-marc         ###   ########.fr       */
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
**	argv[1] = "name_of_the_file"	READ FROM text files (in current directory)
**	argv[2] = "name_of_the_file_2"	read a line on the first file than close
**	argv[3] = "S"					the corresponding fd and open the second file
**									on the same fd of the first and read a line
**
**	argv[3] = "name_of_the_file"	READ FROM text files (in current directory)
**	   .    = "name_of_the_file_2"	read a line of each file following the order
**	   .		.					in wich the arguments are passed, then
**	   .		.					it does the same thing but in reverse order,
** 	   .		.					and again in the first order 
**
**									The program treats each argument passed
**									with a different fd
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
		if (*argv[1] == 'C' && !argv[1][1])
		{
			char buf[BUFFER_SIZE];
			int n;

			while ((n = read(0, buf, BUFFER_SIZE)) > 0)
				write(1, buf, n);

			return (0);
		}
		if (*argv[1] == '0' && !argv[1][1])
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
			{
				printf("An error happened\n");
				printf("%s\n", *line);
			}
			else if (check == 0)
			{
				printf("EOF has been reached\n");
				printf("%s\n", *line);
			}
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
				{
					printf("An error happened\n");
					printf("%s\n", *line);
				}
				else if (check == 0)
				{
					printf("EOF has been reached\n");
					printf("%s\n", *line);
				}
			}

			return (0);
		}
	}
	if (argc == 3)
	{
		if (*argv[1] && *argv[2] == 'E' && !argv[2][1])
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
	if (argc > 3)
	{
		if (argc == 4 && *argv[3] == 'S' && !argv[3][1])
		{
			int fd;
			char *p_line;
			char **line;
			int check;

			p_line = NULL;
			line = &p_line;
			if ((fd = open(argv[1], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[1]);
			else
			{	
				printf("\n--- FILE ---\n");
				check = get_next_line(fd, line);
				if (check == 1)
				{
					printf("\n--- LINE of fd : %d ( %s ) ---\n", fd, argv[1]);
					printf("%s\n", *line);
				}
				else if (!check)
				{
					printf("\n--- EOF for fd : %d ( %s ) ---\n", fd, argv[1]);
					printf("%s\n", *line);
				}
				else
				{
					printf("\n--- An error happened for fd : %d ( %s ) ---\n", fd, argv[1]);
					printf("%s\n", *line);
				}
			}
			if ((fd = close(fd)) == -1)
				printf("can't close %s\n", argv[1]);
			else
			{
				if ((fd = open(argv[2], O_RDONLY)) == -1)
					printf("can't open %s\n", argv[2]);
				else
				{
					printf("\n--- FILE ---\n");
					check = get_next_line(fd, line);
					if (check == 1)
					{
						printf("\n--- LINE of fd : %d ( %s ) ---\n", fd, argv[2]);
						printf("%s\n", *line);
					}
					else if (!check)
					{
						printf("\n--- EOF for fd : %d ( %s ) ---\n", fd, argv[2]);
						printf("%s\n", *line);
					}
					else
					{
						printf("\n--- An error happened for fd : %d ( %s ) ---\n", fd, argv[2]);
						printf("%s\n", *line);
					}
				}
			}

			return (0);
		}

		int i;
		int j;
		int *fildes;

		i = 1;
		j = 0;
		if (!(fildes = malloc((argc - 1)*sizeof(*fildes))))
			return (0);
		printf("\n--- OPEN ERROR REPORT ---\n");
		while (i < argc && j < argc - 1)
		{
			if ((fildes[j] = open(argv[i], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[i]);
			i++;
			j++;
		}
		j = 0;
		char *p_line;
		char **line;
		int check;

		p_line = NULL;
		line = &p_line;
		printf("\n--- GET NEXT LINE OUTPUT ---\n");
		while (j < argc - 1)
		{
			check = get_next_line(fildes[j], line);
			if (check == 1)
			{
				printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else if (!check)
			{
				printf("\n--- EOF for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else
			{
				printf("\n--- An error happened for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			j++;
		}
		j--;
		while (j >= 0)
		{
			check = get_next_line(fildes[j], line);
			if (check == 1)
			{
				printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else if (!check)
			{
				printf("\n--- EOF for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else
			{
				printf("\n--- An error happened for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			j--;
		}
		j++;
		while (j < argc - 1)
		{
			check = get_next_line(fildes[j], line);
			if (check == 1)
			{
				printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else if (!check)
			{
				printf("\n--- EOF for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			else
			{
				printf("\n--- An error happened for fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
				printf("%s\n", *line);
			}
			j++;
		}

		return (0);
	}

	return (0);
}
