NAME		= libft.a

CC			= cc
CFLAGS		= -Wall -Wextra -Werror

SRCS_DIR	= srcs
INC_DIR		= includes

SRCS		= ft_putchar.c \
			  ft_putstr.c \
			  ft_strcmp.c \
			  ft_strlen.c \
			  ft_swap.c

SRC			= $(addprefix $(SRCS_DIR)/, $(SRCS))
OBJS		= $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	ar rcs $@ $^

%.o: %.c
	$(CC) $(CFLAGS) -I $(INC_DIR) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re