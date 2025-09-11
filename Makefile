NAME=minishell
CC=cc
CFLAGS=-Wall -Wextra -Werror -g
SRCS= main.c \
	minishell.c \
	ft_strndup.c \
	ft_strjoin_char.c \
	parsing/parser.c \
	parsing/tokenizer.c \
	parsing/parse_command.c \
	parsing/parsing_cleanup.c \
	execution/echo.c \
	execution/execution.c \
	execution/pwd.c \
	execution/env.c


OBJS = $(SRCS:.c=.o)

HEADERS=-I libft -I include

LIBFT_DIR=./libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus libft

all: $(NAME)

$(NAME): $(OBJS) libft Makefile
	$(CC) $(OBJS) $(LIBFT_ARCHIVE) -lreadline -o $(NAME)

%.o: %.c Makefile
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

libft:
	$(MAKE) -s -C $(LIBFT_DIR) bonus

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
