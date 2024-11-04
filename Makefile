# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yohurteb <yohurteb@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/06/19 13:24:18 by yohurteb          #+#    #+#              #
#    Updated: 2024/11/04 13:58:14 by yohurteb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = cub3D

CC = cc -g

INCLUDES = include

MLX = minilibx-linux

LIBFT = libft

LIBS = -L libft -lft -I libft/includes/

CFLAGS = -Wall -Werror -Wextra -I$(MLX) -I$(INCLUDES)
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
	src/parsing/skip_no_map.c \
	src/parsing/utils_parsing/utils.c \
	src/parsing/utils_parsing/utils_two.c \
	src/parsing/utils_parsing/utils_three.c \
	src/raycasting/raycasting.c \
	src/raycasting/handle_key.c \
	src/raycasting/ray_utils.c \
	src/raycasting/make_wall.c

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
	$(MAKE) -C $(LIBFT) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT) fclean
	$(MAKE) -C $(MLX) clean

re: fclean all

.PHONY: all clean fclean re
