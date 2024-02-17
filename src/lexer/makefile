# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:14:35 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/15 16:42:31 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************** STRUCTURE ************************************ #
# - ../../.objs/lexer -> Folder with object files  
# - *.c -> code files                                                          #
# - lexer.a -> library file                                                    #
# **************************************************************************** #
NAME = lexer.a
SRC_DIR = 
OBJ_DIR = ../../.objs/lexer
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
SRC =	$(SRC_DIR)/ft_lexer.c \
		$(SRC_DIR)/ft_lexer_aux.c \
		$(SRC_DIR)/lexer_aux.c \
		$(SRC_DIR)/lexer_check_first_word.c \
		$(SRC_DIR)/lexer_check_intermediate_word.c \
		$(SRC_DIR)/lexer_check_intermediate_word_aux.c \
		$(SRC_DIR)/lexer_check_last_word.c \
		$(SRC_DIR)/lexer_free_memory.c \
		$(SRC_DIR)/lexer_sort.c \
		$(SRC_DIR)/lexer_replace.c \
		$(SRC_DIR)/lexer_debug.c \
		$(SRC_DIR)/lexer_syntax_error.c \
		$(SRC_DIR)/lexer_check.c 
		
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
		@ar rcs ${DESTINATION}${NAME} ${OBJ}  ../../.objs/libft/*.o

$(OBJ_DIR)/%.o: %.c
		@mkdir -p $(OBJ_DIR)
		@echo "$(GREY)Compiling.............................$(ORANGE)$(<F)"
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
		@echo "$(ORANGE)╔════════════════════════════════════╗"
		@echo "$(ORANGE)║       ${DARK_BLUE} 🗑️  LEXER REMOVED 🗑️ ${ORANGE}         ║"
		@echo "$(ORANGE)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
