# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/17 14:24:44 by xamayuel          #+#    #+#              #
#    Updated: 2024/03/06 11:53:34 by javigarc         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


# ************************ STRUCTURE ***************************************** #
# - .objs --> folder with object files
# - src ---> folder with source files
# - libraries --> folder with library files *.a
# - includes --> folder with *.h files
# **************************************************************************** #
NAME = cub3d
SRC_DIR = src
OBJ_DIR = .objs
LIBRARIES_DIR = libraries
LIBFT_DIR = src/libft
MLX_DIR = minilibx_opengl
MAP_DIR = src/map
GNL_DIR = src/gnl
PARSER_DIR = src/parser
GAME_DIR = src/game
LIBFT = $(LIBRARIES_DIR)/libft.a
MAP = $(LIBRARIES_DIR)/map.a
GNL = $(LIBRARIES_DIR)/gnl.a
PARSER = $(LIBRARIES_DIR)/parser.a
GAME = $(LIBRARIES_DIR)/game.a
MINILIBX = minilibx_linux/libmlx.a
MLX = $(MLX_DIR)/libmlx.a
# ------------- COLORS 
# https://talyian.github.io/ansicolors/
RESET			= 	\033[0m
GREEN 			= 	\033[38;5;46m
WHITE 			= 	\033[38;5;15m
GREY 			= 	\033[38;5;8m
ORANGE 			= 	\033[38;5;202m
RED 			= 	\033[38;5;160m
PINK			=   \033[38;5;162m
LIGHT_PINK      =   \033[38;5;200m
BLUE			= 	\033[38;5;39m
DARK_BLUE		=   \033[38;5;57m
# -----------------SRC
SRC =	$(SRC_DIR)/main.c \
		$(SRC_DIR)/ft_is_valid_input_file.c\
		$(SRC_DIR)/ft_print_data.c\
		$(SRC_DIR)/ft_show_logo.c\

OBJ = $(patsubst $(SRC_DIR)%.c, $(OBJ_DIR)%.o, $(SRC))

CC = gcc

HEAD = -I./includes \
	   -I./$(LIBFT_DIR) \
	   -I./minilibx_opengl

HEAD_LINUX = -I./includes \
	   -I./$(LIBFT_DIR) \
	   -I./minilibx_linux 
	   
CFLAGS = -Wall -Werror -Wextra #-g -fsanitize=address
LFLAGS = -L . $(LIBFT) \
		 -L . $(GNL) \
		 -L . $(MAP)\
		 -L . $(PARSER) \
		 -L . $(GAME) \
		 -L . $(MLX) -framework OpenGL -framework AppKit

LFLAGS_LINUX = -L . $(LIBFT) \
		 -L . $(GNL) \
		 -L . $(MAP)\
		 -L . $(PARSER) \
		 -L . $(GAME) \
		 -L . $(MINILIBX) -lXext -lX11 -lm 
# Address sanitizing flags
ASAN := -fsanitize=address -fsanitize-recover=address
ASAN += -fno-omit-frame-pointer -fno-common
ASAN += -fsanitize=pointer-subtract -fsanitize=pointer-compare
# Technicaly UBSan but works with ASan
ASAN += -fsanitize=undefined
# Technicaly LSan but works with ASan
# ASAN += -fsanitize=leak
# Thread sanitizing flags
TSAN := -fsanitize=thread
# Memory sanitizing flags
MSAN := -fsanitize=memory -fsanitize-memory-track-origins
RM = /bin/rm -rf

all: $(NAME)
bonus: all

minilibx:
	@if [ "$(shell uname)" = "Linux" ]; then \
		echo "Generando para Linux..."; \
		make -C minilibx_linux/; \
	else \
		cd $(MLX_DIR) && make -C.; \
	fi
	

$(NAME): $(OBJ) libraries minilibx libft gnl map parser game
		@if [ "$(shell uname)" = "Linux" ]; then \
			echo "$(ORANGE)Compiling for Linux."; \
			$(CC) $(OBJ) $(HEAD_LINUX) $(CFLAGS) $(LFLAGS_LINUX)  -o $(NAME);\
		else \
			$(CC) $(OBJ) $(HEAD) $(CFLAGS) $(LFLAGS) -o $(NAME); \
		fi
		clear
		@echo "$(LIGHT_PINK)╔════════════════════════════════════╗"
		@echo "$(LIGHT_PINK)║${PINK} 🎮🎮🎮🐶 CUB3D COMPLETE 🐶🎮🎮🎮  $(LIGHT_PINK) ║"
		@echo "$(LIGHT_PINK)╚════════════════════════════════════╝ $(RESET)"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(ORANGE)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

libraries:
	mkdir -p libraries
libft:
		@make -C $(LIBFT_DIR)

map:
		@make -C $(MAP_DIR)
gnl:
		@make -C $(GNL_DIR)	
parser:
		@make -C $(PARSER_DIR)
game:
		@make -C $(GAME_DIR)
mlx:	
		@make -C $(MLX_DIR)	
clean:
		@$(RM) $(OBJ_DIR)
		@echo "Limpiando MiniLibX..."
		@make -C $(MLX_DIR) clean
		sleep .1
		clear

fclean: clean
		@$(RM) libraries/*.a
		@$(RM) $(NAME)
		@echo "Limpiando MiniLibX (fclean)..."
		@make -C $(MLX_DIR) clean
		sleep .1
		clear
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║          ${DARK_BLUE} 🗑️  ALL CLEAN 🗑️ ${BLUE}          ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re 

installation: 
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║ ${DARK_BLUE} 🗑️  INSTALLATION COMPLETE 🗑️ ${BLUE}       ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

