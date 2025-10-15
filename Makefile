# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 16:38:52 by liferrei          #+#    #+#              #
#    Updated: 2025/10/15 17:46:38 by liferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

# Compiler
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Libft
LIBFT_PATH = libft/
LIBFT_NAME = libft.a
LIBFT = $(LIBFT_PATH)$(LIBFT_NAME)

# Includes
INC = -I ./includes/ -I ./libft/

# Sources
SRC_PATH = src/
SRC_FILES = aux_organize.c \
            aux_operations.c \
            organize.c \
            aux_main.c \
            push.c \
            reverse_rotate.c \
            rotate.c \
            swap.c \
            validation.c \
            main.c

SRC = $(addprefix $(SRC_PATH), $(SRC_FILES))

# Objects (dentro de obj/)
OBJ_PATH = obj/
OBJ_FILES = $(SRC_FILES:.c=.o)
OBJ = $(addprefix $(OBJ_PATH), $(OBJ_FILES))

# ---------------------------------------------------------------------------- #
# Cria pasta obj/ se não existir
$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

# Regra para compilar cada objeto de src/ em obj/
$(OBJ_PATH)%.o: $(SRC_PATH)%.c | $(OBJ_PATH)
	@echo "Compiling $<..."
	$(CC) $(CFLAGS) -c $< -o $@ $(INC)

# Compila libft
$(LIBFT):
	@echo "Compiling libft..."
	@make -sC $(LIBFT_PATH)

# Regra principal: compila objetos e linka
all: $(NAME)

$(NAME): $(OBJ) $(LIBFT)
	@echo "Linking $(NAME)..."
	$(CC) $(CFLAGS) -o $@ $(OBJ) $(LIBFT)
	@echo "$(NAME) ready."

# ---------------------------------------------------------------------------- #
# Limpar objetos
clean:
	@echo "Removing object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(LIBFT_PATH)

# Limpar tudo incluindo executável e libft
fclean: clean
	@echo "Removing executable and libft..."
	@rm -f $(NAME)
	@rm -f $(LIBFT)

# Recompilar tudo
re: fclean all

.PHONY: all re clean fclean