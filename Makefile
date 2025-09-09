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


OBJS = $(SRCS:.c=.o)

HEADERS=-I libft -I include

LIBFT_DIR=./libft
LIBFT_ARCHIVE=$(LIBFT_DIR)/libft.a

.PHONY: all clean fclean re bonus

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT_ARCHIVE)
	$(CC) $(OBJS) $(LIBFT_ARCHIVE) -lreadline -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) $(HEADERS) -c $< -o $@

$(LIBFT_ARCHIVE):
	$(MAKE) -s -C $(LIBFT_DIR) bonus

clean:
	@rm -f $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all
