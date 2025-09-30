# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/09/13 16:38:52 by liferrei          #+#    #+#              #
#    Updated: 2025/09/13 17:41:44 by liferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fractol

# Compiler
CC		= gcc
CFLAGS	= -Werror -Wextra -Wall 

# Minilibx
MLX_PATH	= mlx/
MLX_NAME	= libmlx.a
MLX			= $(MLX_PATH)$(MLX_NAME)

# Libft
LIBFT_PATH	= libft/
LIBFT_NAME	= libft.a
LIBFT		= $(LIBFT_PATH)$(LIBFT_NAME)

FT_PRINTF_PATH	= libft/ft_printf/
FT_PRINTF_NAME	= libftprintf.a
FT_PRINTF		= $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)

# Includes
INC			=	-I ./includes/\
				-I ./libft/\
				-I ./minilibx-linux/\
				-I ./libft/ft_printf

# Sources
SRC_PATH	=	src/
SRC			=	main.c \
				ft_events.c \
				ft_init_fractol.c \
				ft_is_valid.c \
				ft_utils.c \
				ft_draw_julia.c \
				ft_draw_mandelbrot.c \
				ft_utils_.c \
			
SRCS		= $(addprefix $(SRC_PATH), $(SRC))

# Objects
OBJ_PATH	= obj/
OBJ			= $(SRC:.c=.o)
OBJS		= $(addprefix $(OBJ_PATH), $(OBJ))

all: $(MLX) $(LIBFT) $(FT_PRINTF) $(NAME)

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(INC)

$(OBJS): $(OBJ_PATH)

$(OBJ_PATH):
	@mkdir $(OBJ_PATH)


$(MLX):
	@echo "Making MiniLibX..."
	@make -sC $(MLX_PATH)

$(LIBFT):
	@echo "Making libft..."
	@make -sC $(LIBFT_PATH)
	
$(FT_PRINTF):
	@echo "Making ft_printf..."
	@make -sC $(FT_PRINTF_PATH)

$(NAME): $(OBJS)
	@echo "Compiling fractol..."
	@$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(MLX) $(LIBFT) $(FT_PRINTF) $(INC) -lXext -lX11 -lm
	@echo "Fractol ready."

bonus: all

clean:
	@echo "Removing .o object files..."
	@rm -rf $(OBJ_PATH)
	@make clean -C $(MLX_PATH)
	@make clean -C $(LIBFT_PATH)
	@make clean -C $(FT_PRINTF_PATH)
	

fclean: clean
	@echo "Removing fractol..."
	@rm -f $(NAME)
	@rm -f $(LIBFT_PATH)$(LIBFT_NAME)
	@rm -f $(FT_PRINTF_PATH)$(FT_PRINTF_NAME)
	

re: fclean all

.PHONY: all re clean fclean