# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: liferrei <liferrei@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/07/14 11:46:06 by liferrei          #+#    #+#              #
#    Updated: 2025/10/15 15:04:35 by liferrei         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC = \
	ft_isdigit.c ft_split.c lst_size.c \
	ft_strlen.c ft_memset.c ft_lst_add_back.c\
	ft_memcpy.c	ft_memmove.c ft_strlcpy.c \
	ft_calloc.c ft_strdup.c ft_substr.c \
	ft_atol.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

bonus: $(OBJ)
	$(AR) $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re bonus