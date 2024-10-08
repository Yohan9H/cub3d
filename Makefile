# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:24:18 by yohurteb          #+#    #+#              #
#    Updated: 2024/10/08 10:55:02 by yohurteb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3d

CC = cc

INCLUDES = include

MLX = minilibx-linux

CFLAGS = -Wall -Werror -Wextra -I$(MLX) -I$(INCLUDES) -g
MLXFLAGS = -L$(MLX) -lmlx -lmlx_Linux -lXext -lm -lbsd -lX11

SRC = 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): ${OBJS}
	$(MAKE) -C $(MLX)
	$(CC) $(CFLAGS) $(OBJS) $(MLXFLAGS) -o $(NAME)

clean:
	rm -rf $(SRC:.c=.o)
	$(MAKE) -C ./minilibx-linux clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all, clean, fclean, re
