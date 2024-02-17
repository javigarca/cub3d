# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:14:35 by xamayuel          #+#    #+#              #
#    Updated: 2022/05/31 13:05:45 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************** STRUCTURE ************************************ #
# - ../../.objs/parser-> Folder with object files  
# - *.c -> code files                                                          #
# - lexer.a -> library file                                                    #
# **************************************************************************** #

NAME = parser.a
SRC_DIR = 
OBJ_DIR = ../../.objs/parser
LIBFT_DIR = ../libft
LIBFT = $(LIBFT_DIR)/libft.a
DESTINATION = ../../libraries/
# ------------- COLORS
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
SRC =	$(SRC_DIR)/ft_parser.c \
		$(SRC_DIR)/parser_create_args_list.c \
		$(SRC_DIR)/parser_create_cmd_list.c \
		$(SRC_DIR)/parser_create_command_list.c \
		$(SRC_DIR)/parser_create_pipe_list.c \
		$(SRC_DIR)/parser_create_redir_list.c \
		$(SRC_DIR)/parser_free_memory.c \
		$(SRC_DIR)/parser_debug.c	
		
OBJ = $(patsubst %.c, $(OBJ_DIR)%.o, $(SRC))
CC = gcc
HEAD = -I ../../includes \
	   -I $(LIBFT_DIR) 
CFLAGS = -Wall -Werror -Wextra
LFLAGS = -L ./$(LIBFT_DIR) 
RM = /bin/rm -rf

all: $(NAME)

$(NAME): $(OBJ) $(LIBFT) 
		@${MAKE} -C ../libft 
		@ar rcs ${DESTINATION}${NAME} ${OBJ} ../../.objs/libft/*.o

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(DARK_BLUE)$(<F)"
		@$(CC) $(CFLAGS) $(HEAD)  -c $< -o $@
		@echo "$(GREEN)DONE!$(GREY)"
		@sleep .2

$(LIBFT):
		@make -C $(LIBFT_DIR) 
		
clean:
		@$(RM) $(OBJ_DIR)
		sleep .1
		clear

fclean: clean
		@$(RM) ${DESTINATION}$(NAME)
		sleep .1
		clear
		@echo "$(BLUE)╔════════════════════════════════════╗"
		@echo "$(BLUE)║       ${DARK_BLUE} 🗑️  PARSER REMOVED 🗑️ ${BLUE}    ║"
		@echo "$(BLUE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
