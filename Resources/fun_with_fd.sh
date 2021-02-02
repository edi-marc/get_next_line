# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    fun_with_fd.sh                                     :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/02 12:26:14 by edi-marc          #+#    #+#              #
#    Updated: 2021/02/02 12:35:06 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash
#
#	simple script that shows the use of file descriptors from the shell
#

#	create a file called foo in the current directory
touch foo

#	exec is useful when you want to run a command, but you don't want a bash shell
#	to be the parent process. When you exec a command, it replaces bash entirely
#
#	i.e. exec bash
#
#	execute bash as an indipendent process not a child process of the current shell;
#
#	this command opens the file descriptor 3 associating it with the file "foo"
#	both in input and output
exec 3<>foo

#	Wtite to file
#	Redirecting the stdout and stderr of the shell to the file
echo "This is a test" >&3
echo "Today is $(date)" >&3

#	close fd 3
#	now you can't access the file "foo" with fd 3
exec 3>&-

#	now fd 3 is associated to bar, if bar doesn't exist, it is created
exec 3<>bar

#	Write to file
echo "This is a second test" >&3
echo "Today is $(date)" >&3

#	close fd 3
exec 3>&-

#	open a new fd 4
exec 4<>foobar

#	write to fd 4
echo "foo:" >&4
cat foo >&4
echo >&4
echo "bar:" >&4
cat bar >&4

#	close fd 4
exec 4>&-

#	show the content
cat foobar

#	remove the content
rm foo bar foobar
