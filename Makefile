# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: amonfret <amonfret@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 12:17:39 by lcollong          #+#    #+#              #
#    Updated: 2025/03/18 20:38:51 by amonfret         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Variables

NAME = cub3D
CC = cc
CFLAGS += -Wall -Wextra -Werror -g

SRC_DIR = src
PARSING_DIR = parsing
RENDER_DIR = render
GNL_DIR = get_next_line
OBJ_DIR = obj

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

MLX_DIR = MLX42
MLX_BUILD_DIR = $(MLX_DIR)/build
MLX = $(MLX_BUILD_DIR)/libmlx42.a

SRC = 	$(SRC_DIR)/main.c \
		$(SRC_DIR)/get_next_line.c \
		$(SRC_DIR)/$(PARSING_DIR)/parse.c \
		$(SRC_DIR)/$(PARSING_DIR)/textures.c \
		$(SRC_DIR)/$(PARSING_DIR)/colors_floor_ceiling.c \
		$(SRC_DIR)/$(PARSING_DIR)/map.c \
		$(SRC_DIR)/$(PARSING_DIR)/walls.c \
		$(SRC_DIR)/$(PARSING_DIR)/utils.c \
		$(SRC_DIR)/$(RENDER_DIR)/render.c \
		$(SRC_DIR)/$(RENDER_DIR)/drawing.c \
		$(SRC_DIR)/$(RENDER_DIR)/vertical_line.c \
		$(SRC_DIR)/$(RENDER_DIR)/init_render_data.c \
		$(SRC_DIR)/$(RENDER_DIR)/init_render_data_utils.c \
		$(SRC_DIR)/init.c \
		$(SRC_DIR)/textures.c \
		$(SRC_DIR)/input.c \
		$(SRC_DIR)/utils.c \
		$(SRC_DIR)/cleanup.c

OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Rules

all: $(LIBFT) $(MLX) $(NAME)

$(LIBFT):
	@echo "\n📦 Buffering Libft... 📦\n"
	make -C $(LIBFT_DIR)

$(MLX) :
	@echo "\n🎨 Buffering MiniLibX... 🎨\n"
	@mkdir -p $(MLX_BUILD_DIR)
	cd $(MLX_BUILD_DIR) && cmake .. && make

$(NAME): $(OBJ) $(LIBFT) $(MLX)
	$(CC) $(CFLAGS) $(OBJ) -L$(LIBFT_DIR) -lft -L$(MLX_BUILD_DIR) -lmlx42 -Iinclude -ldl -lglfw -pthread -lm -o $(NAME)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -I$(MLX_DIR)/include -I$(LIBFT_DIR) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)
	make clean -C $(LIBFT_DIR)
	make clean -C $(MLX_BUILD_DIR)

fclean: clean
	rm -f $(NAME)
	make fclean -C $(LIBFT_DIR)
	rm -rf $(MLX_BUILD_DIR)

re: fclean all

.PHONY: all clean fclean re
