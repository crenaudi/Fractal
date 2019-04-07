# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: crenaudi <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/13 14:13:30 by crenaudi          #+#    #+#              #
#    Updated: 2019/03/29 15:38:04 by crenaudi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = gfx.a
AR = ar rc
CC = gcc
RL = ranlib
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -c
SRC = ft_gfx.c		\
	  lerp.c				\
	  raddeg.c			\
		normalize.c		\
		product.c			\
		rotation.c		\
	  scale.c
OBJ = $(SRC:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(CFLAGS) -g3 $(SRC) -I .
	@$(AR) $(NAME) $(OBJ)
	@$(RL) $(NAME)
	@echo "/// all gfx ///"

clean:
	@$(RM) $(OBJ)
	@echo "/// clean gfx ///"

fclean: clean
	@$(RM) $(NAME)
	@echo "/// fclean gfx ///"

re: fclean all
