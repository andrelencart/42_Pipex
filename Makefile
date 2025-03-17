# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:43:01 by andcarva          #+#    #+#              #
#    Updated: 2025/03/17 13:06:10 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
OBJ_DIR= Obj_pipex
SRC_DIR= Src
LIBFT = Includes/Libft/libft.a

SRC_FILES= pipex.c error.c process.c split_pipe.c
 
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT)
	@echo "\e[1;91mCOMPILING PIPEX ..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\e[1;91mDONE!!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./Includes/Libft -s

clean:
	@echo "\e[1;33mClEANING PIPE ..."
	@rm -rf $(OBJ_DIR)
	@make clean -C ./Includes/Libft -s
	@echo "\e[1;33mPIPE CLEANED!!"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	
re: fclean all

.PHONY: all fclean clean re