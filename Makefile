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
THREAD = -lpthread
LIBFT_FOLDER = src/libft
LIB = -L./$(LIBFT_FOLDER) -lft
LIBFT = $(LIBFT_FOLDER)/libft.a
LIBGFX_FOLDER = src/libgfx
LIB2 = -L./$(LIBGFX_FOLDER) -lft
LIBGFX = $(LIBGFX_FOLDER)/gfx.a
FDF_FOLDER = src/bonus
LIB3 = -L./$(FDF_FOLDER) -lft
FDF = $(FDF_FOLDER)/fdf.a
RM = rm -f
SRC = src/main.c								\
			src/cal.c									\
			src/buddhabrot.c					\
			src/color_print.c					\
			src/init.c								\
			src/info.c								\
			src/clean.c								\
			src/bonus.c								\
			src/tools_mouse.c					\
			src/tools_key.c
OBJ = $(SRC:.c=.o)

%.o: %.c includes/fractol.h
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: all fclean re

all: $(NAME)

$(LIBFT):
	@make -sC $(LIBFT_FOLDER)

$(LIBGFX):
	@make -sC $(LIBGFX_FOLDER)

$(FDF):
	@make -sC $(FDF_FOLDER)

$(NAME): $(OBJ) $(LIBFT) $(LIBGFX) $(FDF)
	@echo		"\033[0;32m [OK] \033[0m       \033[0;33m Compiling:\033[0m" $<
	@$(CC) -g3 $(MINILIBX) $(FRAMEWORK) $(THREAD) -o $(NAME) $(LIB_MATH) $(LIB) $(LIBFT) $(LIB2) $(LIBGFX) $(LIB3) $(FDF) $(OBJ)
	@echo		"\033[0;33m [FRACTOL][SUCCESS] \033[0m"

clean:
	@$(RM) $(OBJ)
	@make -sC $(LIBFT_FOLDER) clean
	@make -sC $(LIBGFX_FOLDER) clean
	@make -sC $(FDF_FOLDER) clean
	@echo		"\033[0;34m [CLEAN][SUCCESS] \033[0m"

fclean: clean
	@$(RM) $(NAME)
	@make -sC $(LIBFT_FOLDER) fclean
	@make -sC $(LIBGFX_FOLDER) fclean
	@make -sC $(FDF_FOLDER) fclean
	@echo		"\033[0;34m [FCLEAN][SUCCESS] \033[0m"

re: fclean all
