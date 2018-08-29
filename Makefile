# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kkostrub <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/08/15 12:46:32 by kkostrub          #+#    #+#              #
#    Updated: 2018/08/15 12:46:35 by kkostrub         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractol

SRC_PATH = srcs
OBJ_PATH = obj
INC_PATH = include

SRC = main.c\
	  calc.c\
	  fractals.c\
	  action.c\
	  addition.c\
	  hints.c\
	  mouse.c

INC = -I $(INC_PATH)

INC2 = -I /usr/locale/include

OBJ = $(addprefix $(OBJ_PATH)/,$(SRC:.c=.o))

LIBFT =	libft/libft.a

CC = gcc

FLAGS = -Wall -Wextra -Werror

FRMWR = -framework OpenGL -framework AppKit

MLX_LIB = -L /usr/local/lib/ -lmlx

all: $(NAME)

$(NAME): $(LIBFT) $(OBJ)
	$(CC) $(OBJ) $(INC2) -o $(NAME) $(LIBFT) $(FRMWR) $(MLX_LIB)

$(OBJ_PATH)/%.o: $(SRC_PATH)/%.c
	@mkdir $(OBJ_PATH) 2> /dev/null || true
	$(CC) -c $(FLAGS) $< -o $@ $(INC) $(INC2)

$(LIBFT):
		make -C libft

clean:
		rm -rf $(OBJ_PATH)
		make clean -C libft

fclean: clean
		rm -rf $(NAME)
		make fclean -C libft

re: fclean all

norm:
	norminette -R CheckForbiddenSourceHeader libft/*.c libft/*.h $(SRC_PATH)/*.c $(INC_PATH)/*.h

.PHONY : all, re, clean, flcean, norm
