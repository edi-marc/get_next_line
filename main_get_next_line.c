/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_get_next_line.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emdi-mar <emdi-mar@student.42roma.it>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 11:00:21 by emdi-mar          #+#    #+#             */
/*   Updated: 2025/02/18 11:45:48 by emdi-mar         ###   ########.fr       */
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
#include <fcntl.h>

int main(int argc, char **argv)
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
			char	*line;

			line = NULL;
			printf("\n--- LETTURA E SCRITTURA FROM FD 0 ---\n");
			line = get_next_line(0);
			printf("%s", line);
			return (0);
		}
		if (*argv[1])
		{
			int fd;

			if ((fd = open(argv[1], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[1]);
			else
			{	
				char *line;

				line = NULL;
				printf("\n--- LETTURA DAL FILE ---\n");
				line = get_next_line(fd);
				printf("%s", line);
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
			{	char	*line;

				printf("\n--- FILE ---\n");
				line = get_next_line(fd);
				while (line)
				{
					printf("%s", line);
					line = get_next_line(fd);
				}
			}

			return (0);
		}
	}
	if (argc > 3)
	{
		char	*p_line;
		char	**line;
		if (argc == 4 && *argv[3] == 'S' && !argv[3][1])
		{
			int fd;

			p_line = NULL;
			line = &p_line;
			if ((fd = open(argv[1], O_RDONLY)) == -1)
				printf("can't open %s\n", argv[1]);
			else
			{	
				printf("\n--- FILE ---\n");
				*line = get_next_line(fd);
				printf("\n--- LINE of fd : %d ( %s ) ---\n", fd, argv[1]);
				printf("%s", *line);
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
					printf("\n--- LINE of fd : %d ( %s ) ---\n", fd, argv[2]);
					*line = get_next_line(fd);
					printf("%s", *line);
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

		p_line = NULL;
		line = &p_line;
		printf("\n--- GET NEXT LINE OUTPUT ---\n");
		while (j < argc - 1)
		{
			*line = get_next_line(fildes[j]);
			printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
			printf("%s", *line);
			j++;
		}
		j--;
		while (j >= 0)
		{
			*line = get_next_line(fildes[j]);
			printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
			printf("%s", *line);
			j--;
		}
		j++;
		while (j < argc - 1)
		{
			*line = get_next_line(fildes[j]);
			printf("\n--- LINE of fd : %d ( %s ) ---\n", fildes[j], argv[j + 1]);
			printf("%s", *line);
			j++;
		}

		return (0);
	}

	return (0);

}

