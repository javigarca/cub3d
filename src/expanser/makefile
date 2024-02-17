# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:14:35 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/13 20:01:24 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************** STRUCTURE ************************************ #
# - ../../.objs/expanser -> Folder with object files  
# - *.c -> code files                                                          #
# - lexer.a -> library file                                                    #
# **************************************************************************** #
NAME = expanser.a
SRC_DIR = 
OBJ_DIR = ../../.objs/expanser
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
SRC =	$(SRC_DIR)/ft_expansion.c \
		$(SRC_DIR)/expansion_quotes_dollar.c \
		$(SRC_DIR)/expansion_args.c  \
		$(SRC_DIR)/expansion_bin.c \
		$(SRC_DIR)/expansion_bin_aux.c \
		$(SRC_DIR)/expansion_cmd.c \
		$(SRC_DIR)/expansion_pipes.c \
		$(SRC_DIR)/expansion_redir.c \
		$(SRC_DIR)/expansion_heredoc.c \
		$(SRC_DIR)/expansion_heredoc_2.c \
		$(SRC_DIR)/expansion_utils.c \
		$(SRC_DIR)/expansion_intdollar.c

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
		@echo "$(GREY)Compiling.............................$(PINK)$(<F)"
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
		@echo "$(PINK)╔════════════════════════════════════╗"
		@echo "$(PINK)║          ${DARK_BLUE} 🗑️  ALL CLEAN 🗑️ ${PINK}          ║"
		@echo "$(PINK)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
