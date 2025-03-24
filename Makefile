# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:43:01 by andcarva          #+#    #+#              #
#    Updated: 2025/03/24 16:15:10 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
OBJ_DIR= Obj_pipex
SRC_DIR= Src/Pipex
BONUS_DIR= Src/Pipex_bonus
LIBFT = Includes/Libft/libft.a

SRC_FILES= pipex.c error.c process.c split_pipe.c
BONUS_FILES= pipex_bonus.c loop.c here_doc.c

OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_BONUS= $(addprefix $(OBJ_DIR)/, $(BONUS_FILES:.c=.o))
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(BONUS_FILES))
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))

all: $(NAME) 

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(OBJ_BONUS)
	@echo "\e[1;91mCOMPILING PIPEX ..."
	@$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\e[1;91mDONE!!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(BONUS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./Includes/Libft -s

bonus: $(SRC_BONUS) $(NAME)
	@echo "\e[1;95mCOMPILING BONUS ..."
	@$(CC) $(CFLAGS) $(OBJ_BONUS) -o $(NAME)
	@echo "\e[1;95mDONE!!"

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