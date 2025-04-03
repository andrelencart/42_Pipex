# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: andcarva <andcarva@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/03/10 15:43:01 by andcarva          #+#    #+#              #
#    Updated: 2025/04/03 12:38:34 by andcarva         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=pipex
CC=cc
CFLAGS= -Wall -Wextra -Werror -g
LIBFT = Includes/Libft/libft.a

MAIN= pipex.c
SRC_FILES= error.c process.c split_pipe.c
SRC_BONUS_FILES= pipex_bonus.c dif_process_bonus.c utils.c

SRC_DIR= Src/Pipex
SRC= $(addprefix $(SRC_DIR)/, $(SRC_FILES))
SRC_MAIN= $(addprefix $(SRC_DIR)/, $(MAIN))

OBJ_DIR= Obj_pipex
OBJ= $(addprefix $(OBJ_DIR)/, $(SRC_FILES:.c=.o))
OBJ_MAIN= $(addprefix $(OBJ_DIR)/, $(MAIN:.c=.o))

SRC_BONUS_DIR= Src/Pipex_bonus
SRC_BONUS = $(addprefix $(BONUS_DIR)/, $(SRC_BONUS_FILES))
OBJ_BONUS= $(addprefix $(OBJ_DIR)/, $(SRC_BONUS_FILES:.c=.o))

all: $(NAME)

$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)

$(NAME): $(OBJ) $(LIBFT) $(OBJ_MAIN)
	@echo "\e[1;91mCOMPILING PIPEX ..."
	@$(CC) $(CFLAGS) $(OBJ_MAIN) $(OBJ) $(LIBFT) -o $(NAME)
	@echo "\e[1;91mDONE!!"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT):
	@make -C ./Includes/Libft -s

bonus: $(OBJ_BONUS) $(NAME) $(OBJ)
	@echo "\e[1;95mCOMPILING BONUS ..."
	@$(CC) $(CFLAGS) $(OBJ) $(OBJ_BONUS) $(LIBFT) -o $(NAME)
	@echo "\e[1;95mDONE!!"

$(OBJ_DIR)/%.o: $(SRC_BONUS_DIR)/%.c | $(OBJ_DIR)
	@$(CC) $(CFLAGS) -c $< -o $@

clean:
	@echo "\e[1;33mClEANING PIPE ..."
	@rm -rf $(OBJ_DIR)
	@make clean -C ./Includes/Libft -s
	@echo "\e[1;33mPIPE CLEANED!!"

fclean: clean
	@rm -rf $(NAME)
	@rm -rf $(LIBFT)
	
re: fclean all

rb: fclean all bonus

.PHONY: all fclean clean re bonus