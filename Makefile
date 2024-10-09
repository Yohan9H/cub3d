# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:24:18 by yohurteb          #+#    #+#              #
#    Updated: 2024/10/09 13:56:59 by yohurteb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

INCLUDES = include

MLX = mlx

LIBFT = libft

LIBS = -L libft -lft -I libft/includes/

CFLAGS = -Wall -Werror -Wextra -I$(MLX) -I$(INCLUDES) -g
MLXFLAGS = -L$(MLX) -lmlx -lmlx_Linux -lXext -lm -lbsd -lX11

SRC = src/main.c \
	src/hook/handle.c \
	src/utils/utils.c \
	src/game/game.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C $(MLX)
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(SRC:.c=.o)
	$(MAKE) -C ./mlx clean
	$(MAKE) -C ./libft clean

fclean: clean
	rm -rf $(NAME)

re: fclean
	make all

.PHONY: all, clean, fclean, re
