# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2019/03/29 15:38:32 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf.a
AR = ar rc
CC = gcc
RL = ranlib
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -c
RM = rm -f
SRC = fdf.c				\
	  trace.c				\
		projection.c	\
		cln.c					\
		lgd.c					\
	  event.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@echo		"\033[0;32m [OK] \033[0m       \033[0;33m Compiling: fdf.a\033[0m"
	@$(CC) $(CFLAGS) -g3 $(SRC) -I .
	@$(AR) $(NAME) $(OBJ)
	@$(RL) $(NAME)
	@echo		"\033[0;33m [BONUS_FDF][SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)

fclean: clean
