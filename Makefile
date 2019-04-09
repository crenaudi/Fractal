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

NAME = fractol
CC = cc
CFLAGS = -Wall -Wextra
CFLAGS += -I./$(LIBGFX_FOLDER)
MINILIBX = -I /usr/local/include/mlx.h -L /usr/local/lib/ -lmlx
FRAMEWORK = -framework OpenGl -framework AppKit
LIB_MATH = -lm
LIBFT_FOLDER = src/libft
LIB = -L./$(LIBFT_FOLDER) -lft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBGFX_FOLDER = src/libgfx
LIB2 = -L./$(LIBGFX_FOLDER) -lft
LIBGFX = $(LIBGFX_FOLDER)/gfx.a
RM = rm -f
SRC = src/main.c \
			src/iterrative_fractal.c \
			src/init.c \
			src/key.c
OBJ = $(SRC:.c=.o)

.PHONY: all fclean re

all: $(NAME)

$(LIBFT):
	make -sC $(LIBFT_FOLDER)

$(LIBGFX):
	make -sC $(LIBGFX_FOLDER)

$(NAME): $(OBJ) $(LIBFT) $(LIBGFX)
	@$(CC) -g3 $(MINILIBX) $(FRAMEWORK) -o $(NAME) $(LIB_MATH) $(LIB) $(LIB2) $(LIBGFX) $(OBJ)
	@echo "/// all fdf ///"

clean:
	@$(RM) $(OBJ)
	make -sC $(LIBFT_FOLDER) clean
	make -sC $(LIBGFX_FOLDER) clean
	@echo "/// clean fdf ///"

fclean: clean
	@$(RM) $(NAME)
	make -sC $(LIBFT_FOLDER) fclean
	make -sC $(LIBGFX_FOLDER) fclean
	@echo "/// fclean fdf ///"

re: fclean all
