# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:24:18 by yohurteb          #+#    #+#              #
#    Updated: 2024/10/18 11:32:28 by yohurteb         ###   ########.fr        #
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
	src/game/game.c \
	src/parsing/parsing.c \
	src/parsing/check_file.c \
	src/parsing/check_file_two.c \
	src/parsing/create_map.c \
	src/parsing/check_map.c \
	src/parsing/utils_parsing/utils.c \
	src/parsing/utils_parsing/utils_two.c \
	src/raycasting/raycasting.c \
	src/test.c

OBJ_DIR = .obj
OBJS = $(addprefix $(OBJ_DIR)/, $(SRC:.c=.o))

all: $(NAME)

$(NAME): $(OBJS)
	$(MAKE) -C $(MLX) all
	$(MAKE) -C $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) $(MLXFLAGS) -o $(NAME)

$(OBJ_DIR)/%.o: %.c
	@mkdir -p $(OBJ_DIR)/$(dir $<)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	$(MAKE) -C $(MLX) clean
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.PHONY: all clean fclean re
