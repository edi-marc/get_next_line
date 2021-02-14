# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: edi-marc <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/02/04 17:24:47 by edi-marc          #+#    #+#              #
#    Updated: 2021/02/14 13:52:10 by edi-marc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gnl

BNAME = gnl_b

SRC = get_next_line.c get_next_line.h get_next_line_utils.c

BSRC = get_next_line_bonus.c get_next_line_bonus.h get_next_line_utils_bonus.c

MAIN = main_get_next_line.c

DB_SYM = *.dSYM

GCH = get_next_line.h.gch get_next_line_bonus.h.gch

CC = gcc

FLAGS = -Wall -Werror -Wextra

DB_FLAG = -g

MFLAGS = -D

BUF = BUFFER_SIZE=

bf =

RENAME = mv

STD_NAME = a.out

RM = /bin/rm -rf

all: $(NAME)

bonus: $(BNAME)

debug: clean $(SRC) $(MAIN)
	@$(CC) $(FLAGS) $(DB_FLAG) $(MFLAGS) $(BUF)$(bf) $(SRC) $(MAIN)

clean: 
	@$(RM) $(GCH) $(NAME) $(BNAME) $(STD_NAME) $(DB_SYM)

re: clean all

rbonus: clean bonus

$(NAME) : $(SRC) $(MAIN)
	@$(CC) $(FLAGS) $(MFLAGS) $(BUF)$(bf) $(SRC) $(MAIN)
	@$(RENAME) $(STD_NAME) $(NAME)
	
$(BNAME) : $(BSRC) $(MAIN)
	@$(CC) $(FLAGS) $(MFLAGS) $(BUF)$(bf) $(BSRC) $(MAIN)
	@$(RENAME) $(STD_NAME) $(BNAME)

.PHONY: all bonus clean re rbonus debug
