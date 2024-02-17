# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: xamayuel <xamayuel@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/05/06 09:14:35 by xamayuel          #+#    #+#              #
#    Updated: 2024/02/14 19:40:06 by xamayuel         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# ***************************** STRUCTURE ************************************ #
# - ../../.objs/executer -> Folder with object files  
# - *.c -> code files                                                          #
# - lexer.a -> library file                                                    #
# **************************************************************************** #
NAME = executer.a
SRC_DIR = 
OBJ_DIR = ../../.objs/executer
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
YELLOW			= 	\033[38;5;3m
O_PINK			= 	\033[38;5;13m
# -----------------SRC
SRC =	$(SRC_DIR)/ft_execution.c \
		$(SRC_DIR)/builtin_clear.c \
		$(SRC_DIR)/ft_builtin_echo.c  \
		$(SRC_DIR)/ft_builtin_export.c  \
		$(SRC_DIR)/ft_builtin_export_aux.c \
		$(SRC_DIR)/ft_builtin_pwd.c  \
		$(SRC_DIR)/ft_builtin_unset.c  \
		$(SRC_DIR)/ft_enviroment_utils.c  \
		$(SRC_DIR)/ft_builtin_env.c  \
		$(SRC_DIR)/ft_redirections.c  \
		$(SRC_DIR)/ft_builtin_cd.c  \
		$(SRC_DIR)/ft_builtin_cd_aux.c \
		$(SRC_DIR)/ft_execution_utils.c \
		$(SRC_DIR)/ft_execution_utils2.c \
		$(SRC_DIR)/ft_execution_error.c \
		$(SRC_DIR)/ft_exit.c \
		$(SRC_DIR)/ft_builtin.c \
		$(SRC_DIR)/executer_error.c \
		$(SRC_DIR)/ft_pipes.c \
		$(SRC_DIR)/ft_pipes_plus.c \
		$(SRC_DIR)/ft_execution_aux.c \
		$(SRC_DIR)/ft_execution_aux2.c 

		
						
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
		@echo "$(GREY)Compiling.............................$(YELLOW)$(<F)"
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
		@echo "$(YELLOW)╔════════════════════════════════════╗"
		@echo "$(YELLOW)║      ${O_PINK} 🗑️  EXECUTER REMOVED 🗑️ ${YELLOW}       ║"
		@echo "$(YELLOW)╚════════════════════════════════════╝ $(RESET)"

re: fclean all

.PONY: all clean fclean re
