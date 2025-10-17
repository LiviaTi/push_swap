

RESET		= \033[0m
GREEN_BOLD	= \033[1;32m
YELLOW_BOLD	= \033[1;33m
RED_BOLD	= \033[1;31m

NAME = libft.a

CC = cc
CFLAGS = -Wall -Werror -Wextra
RM = rm -f
AR = ar rcs

SRC =   ft_atol.c           \
        ft_bzero.c          \
        ft_calloc.c         \
        ft_isdigit.c        \
        ft_memcpy.c         \
        ft_memmove.c        \
        ft_memset.c         \
        ft_split.c          \
        ft_strdup.c         \
        ft_strlcpy.c        \
        ft_strlen.c         \
        ft_substr.c

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@$(AR) $(NAME) $(OBJS)
	@echo "$(GREEN_BOLD)✅ Libft compiled successfully!$(RESET)"

%.o: %.c
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "$(YELLOW_BOLD)Compiling libft:$(RESET) $<"

clean:
	@$(RM) $(OBJS)
	@echo "$(RED_BOLD)🧼 Libft objects removed!$(RESET)"

fclean: clean
	@$(RM) $(NAME)
	@echo "$(RED_BOLD)🧼 Libft project fully cleaned!$(RESET)"

re: fclean all

.PHONY: all clean fclean re bonus